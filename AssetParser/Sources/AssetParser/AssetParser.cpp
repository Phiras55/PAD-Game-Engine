#include <Shlwapi.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <AssetParser/AssetParser.h>
#include "AssetParser.h"

#pragma comment(lib,"shlwapi.lib")

namespace pad		{
namespace parser	{

PARSER_RESULT ParseFile(const std::string& _inputPath, 
						const std::string& _outputPath)
{
	std::string extension	= PathFindExtension(_inputPath.c_str());
	std::string fileName	= PathFindFileName(_inputPath.c_str());

	if (extension == ".fbx")
	{
		if (ParseFBX(_inputPath, _outputPath, fileName) == FAILURE)
			return PARSER_RESULT::FAILURE;
	}

	return PARSER_RESULT::SUCCESS;
}

PARSER_RESULT ParseFBX(	const	std::string& _inputPath, 
						const	std::string& _outputPath,
								std::string& _fileName)
{
	FbxManager*		fbxManager = FbxManager::Create();
	FbxIOSettings*	ioSettings = FbxIOSettings::Create(fbxManager, IOSROOT);

	fbxManager->SetIOSettings(ioSettings);
	FbxImporter* fbxImporter = FbxImporter::Create(fbxManager, "");

	if (!fbxImporter->Initialize(_inputPath.c_str(), -1, fbxManager->GetIOSettings()))
		return PARSER_RESULT::FAILURE;

	FbxScene* fbxScene = FbxScene::Create(fbxManager, "scene");
	fbxImporter->Import(fbxScene);
	fbxImporter->Destroy();

	FbxMesh*		fbxMesh			= nullptr;
	SkeletonData*	skeleton		= nullptr;
	ControlPoint*	controlPoints	= new ControlPoint();

	int i = 0;
	FbxNode* currentNode = fbxScene->GetRootNode();
	while (currentNode->GetChild(i))
	{
		std::string nodeName = currentNode->GetChild(i)->GetName();
		std::replace(nodeName.begin(), nodeName.end(), '/', '_');
		std::replace(nodeName.begin(), nodeName.end(), '\\', '_');


		if (currentNode->GetChild(i)->GetMesh())
		{	
			fbxMesh = currentNode->GetChild(i)->GetMesh();
			ParseMesh(currentNode->GetChild(i), _outputPath, nodeName, controlPoints);
		}			
		else if (currentNode->GetChild(i)->GetSkeleton())
		{
			skeleton = new SkeletonData();
			ParseSkeleton(currentNode->GetChild(i), skeleton);
			if(fbxMesh)
				ParseBoneWeight(_outputPath, nodeName, fbxScene, currentNode->GetChild(i), fbxMesh, skeleton, controlPoints);
			GeneratePADSkeleton(_outputPath, nodeName, skeleton);
			delete skeleton;
		}

		++i;
		if (!currentNode->GetChild(i))
		{
			currentNode = currentNode->GetChild(0);
			i = 0;
		}
	}
	//if (skeleton)
	//	ParseAnimations(fbxScene, skeleton);

	if (controlPoints)
		delete controlPoints;

	fbxScene->Destroy();
	fbxManager->Destroy();

	return PARSER_RESULT::SUCCESS;
}

void ParseMesh(			FbxNode*		const	_node,
				const	std::string&			_outputPath,
				const	std::string&			_fileName,
						ControlPoint*			_controlPoint)
{
	FbxGeometry*					fbxGeometry		= _node->GetGeometry();
	FbxMesh*						fbxMesh			= _node->GetMesh();
	FbxGeometryElementUV*			fbxUVs			= fbxMesh->GetElementUV();

	FbxVector4*						vertexRaw		= fbxGeometry->GetControlPoints();
	FbxGeometryElementNormal*		normalsRaw		= fbxMesh->GetElementNormal();
	int*							indices			= fbxMesh->GetPolygonVertices();
	int								indicesCount	= fbxMesh->GetPolygonVertexCount();
	int								polyCount		= fbxMesh->GetPolygonCount();

	FbxVector4*						vertex			= new FbxVector4[indicesCount];
	FbxVector4*						normals			= new FbxVector4[indicesCount];
	FbxVector2*						uvs				= new FbxVector2[indicesCount];

	_controlPoint->weightInfos = new WeightInfo[indicesCount];

	int index = 0;
	for (int polygonIndex = 0; polygonIndex < polyCount; ++polygonIndex)
	{
		int	polygonIndiceStart = fbxMesh->GetPolygonVertexIndex(polygonIndex);

		for (int vertexIndex = 0; vertexIndex < fbxMesh->GetPolygonSize(polygonIndex); ++vertexIndex)
		{
			vertex[index] = vertexRaw[indices[polygonIndiceStart]];
			_controlPoint->fbxIndicesMyIndice[indices[polygonIndiceStart]].push_back(index);

			ParseNormals(index, polygonIndiceStart, normalsRaw, indices, normals);
			ParseUV(index, fbxUVs, indices, uvs);

			++index;
			++polygonIndiceStart;
		}
	}

	std::string outputFile = _outputPath + _fileName + ".PADMesh";

	GeneratePADMesh(outputFile, indicesCount, indices, vertex, normals, uvs, ParseMaterial(_outputPath, _node));

	delete[] vertex;
	delete[] normals;
	delete[] uvs;
}

void ParseNormals(	int									_index, 
					int									_polygonIndiceStart, 
					FbxGeometryElementNormal*	const	_normalsRaw, 
					int*						const	_indices, 
					FbxVector4*					const	_normals)
{
	int	normalIndex = 0;

	if (_normalsRaw->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
	{
		if (_normalsRaw->GetReferenceMode() == FbxGeometryElement::eDirect)
			normalIndex = _index;

		if (_normalsRaw->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
			normalIndex = _normalsRaw->GetIndexArray().GetAt(_indices[_polygonIndiceStart]);
	}
	else if (_normalsRaw->GetMappingMode() == FbxGeometryElement::eByControlPoint)
	{
		if (_normalsRaw->GetReferenceMode() == FbxGeometryElement::eDirect)
			normalIndex = _indices[_index];

		if (_normalsRaw->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
			normalIndex = _normalsRaw->GetIndexArray().GetAt(_indices[_index]);
	}
	_normals[_index] = _normalsRaw->GetDirectArray().GetAt(normalIndex);
}

void ParseUV(	int								_index, 
				FbxGeometryElementUV*	const	_fbxUVs, 
				int*					const	_indices, 
				FbxVector2*				const	_uvs)
{
	int	uvIndex = 0;

	if (_fbxUVs->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
	{
		if (_fbxUVs->GetReferenceMode() == FbxGeometryElement::eDirect)
			uvIndex = _fbxUVs->GetIndexArray().GetAt(_index);

		if (_fbxUVs->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
			uvIndex = _fbxUVs->GetIndexArray().GetAt(_index);
	}
	else if (_fbxUVs->GetMappingMode() == FbxGeometryElement::eByControlPoint)
	{
		if (_fbxUVs->GetReferenceMode() == FbxGeometryElement::eDirect)
			uvIndex = _indices[_index];

		if (_fbxUVs->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
			uvIndex = _fbxUVs->GetIndexArray().GetAt(_indices[_index]);
	}
	_uvs[_index] = _fbxUVs->GetDirectArray().GetAt(uvIndex);
}

void GeneratePADMesh(	const	std::string&			_outputPath, 
						const	int						_indicesCount,
								int*			const	_indices, 
								FbxVector4*		const	_vertex, 
								FbxVector4*		const	_normals, 
								FbxVector2*		const	_uvs,
						const	std::string&			_materialPath)
{
	std::string resultFile;

	resultFile += "[VERTEX_COUNT]\n";
	resultFile += std::to_string(_indicesCount) + "\n";
	resultFile += "[INDICE_COUNT]\n";
	resultFile += std::to_string(_indicesCount) + "\n";
	resultFile += "[MATERIAL]\n";
	resultFile += _materialPath					+ "\n";

	resultFile += "[POINTS]\n";
	for (int i = 0; i < _indicesCount; ++i)
	{
		resultFile += std::to_string(_vertex[i].mData[0]) + " "
					+ std::to_string(_vertex[i].mData[1]) + " "
					+ std::to_string(_vertex[i].mData[2]) + "\n";
	}
	resultFile += "[NORMALS]\n";
	for (int i = 0; i < _indicesCount; ++i)
	{
		resultFile += std::to_string(_normals[i].mData[0]) + " "
					+ std::to_string(_normals[i].mData[1]) + " "
					+ std::to_string(_normals[i].mData[2]) + "\n";
	}
	resultFile += "[UVS]\n";
	for (int i = 0; i < _indicesCount; ++i)
	{
		resultFile += std::to_string(_uvs[i].mData[0]) + " "
					+ std::to_string(_uvs[i].mData[1]) + "\n";
	}
	resultFile += "[INDICES]\n";
	for (int i = 0; i < _indicesCount; i += 3)
	{
		resultFile += std::to_string(i)		+ " "
					+ std::to_string(i + 1)	+ " "
					+ std::to_string(i + 2)	+ "\n";
	}

	std::ofstream out(_outputPath);
	out << resultFile;
	out.close();
}

void ParseSkeleton(	FbxNode*		const	_currentNode,
					SkeletonData*	const	_skeleton)
{
	ParseSkeletonRecur(_skeleton, _currentNode, 0, -1);
}

void ParseSkeletonRecur(SkeletonData*	const	_skeleton,
						FbxNode*		const	_currentNode,
						int						_id,
						int						_parentId)
{
	FbxNodeAttribute::EType nodeType;
	if (_currentNode->GetNodeAttribute())
		if (_currentNode->GetNodeAttribute()->GetAttributeType())
			nodeType = _currentNode->GetNodeAttribute()->GetAttributeType();

	if (nodeType == FbxNodeAttribute::eSkeleton)
	{
		BoneData* bone	= new BoneData();
		bone->boneName	= _currentNode->GetName();
		bone->id		= _id;
		bone->parentId	= _parentId;
		_skeleton->bones.push_back(bone);

		std::replace(bone->boneName.begin(), bone->boneName.end(), '/', '_');
		std::replace(bone->boneName.begin(), bone->boneName.end(), '\\', '_');
	}
	for (int i = 0; i < _currentNode->GetChildCount(); ++i)
	{
		ParseSkeletonRecur(_skeleton, _currentNode->GetChild(i), _skeleton->bones.size(), _id);
	}
}

void GeneratePADSkeleton(	const	std::string&			_outputPath, 
							const	std::string&			_skeletonName,
									SkeletonData*	const	_skeleton)
{
	std::string resultFile;
	resultFile += "[BONE_COUNT]\n" + std::to_string(_skeleton->bones.size()) + "\n";
	resultFile += "[BONES]\n";
	for (int boneIndex = 0; boneIndex < _skeleton->bones.size(); ++boneIndex)
	{
		resultFile	+=	_skeleton->bones[boneIndex]->boneName
					+	" "
					+	std::to_string(_skeleton->bones[boneIndex]->id) 
					+	" " 
					+	std::to_string(_skeleton->bones[boneIndex]->parentId) 
					+	" ";
		for (int i = 0; i < 16; ++i)
			resultFile += std::to_string(_skeleton->bones[boneIndex]->inverseBindPose[i / 4][i % 4]) + " ";
		resultFile += "\n";
	}

	std::string outputFile = _outputPath + _skeletonName + ".PADSkeleton";
	std::ofstream out(outputFile);
	out << resultFile;
	out.close();
}

std::string ParseMaterial(	const	std::string&			_outputPath,
									FbxNode*		const	_currentNode)
{
	int materialCount = _currentNode->GetMaterialCount();
	for (int materialIndex = 0; materialIndex < materialCount; ++materialIndex)
	{
		FbxSurfaceMaterial* fbxMaterial = _currentNode->GetMaterial(materialIndex);

		if (fbxMaterial)
		{
			AssetMaterial newMaterial;
			newMaterial.name = fbxMaterial->GetName();
			std::replace(newMaterial.name.begin(), newMaterial.name.end(), '/', '_');
			std::replace(newMaterial.name.begin(), newMaterial.name.end(), '\\', '_');

			if (fbxMaterial->GetClassId().Is(FbxSurfacePhong::ClassId))
			{
				FbxSurfacePhong* phongMaterial = (FbxSurfacePhong*)fbxMaterial;

				newMaterial.ambient = math::Vec3f(	phongMaterial->Ambient.Get()[0],
													phongMaterial->Ambient.Get()[1],
													phongMaterial->Ambient.Get()[2]);

				newMaterial.diffuse = math::Vec3f(	phongMaterial->Diffuse.Get()[0],
													phongMaterial->Diffuse.Get()[1],
													phongMaterial->Diffuse.Get()[2]);

				newMaterial.specular = math::Vec3f(	phongMaterial->Specular.Get()[0],
													phongMaterial->Specular.Get()[1],
													phongMaterial->Specular.Get()[2]);

				newMaterial.shininess = phongMaterial->Shininess.Get();
			}
			else if (fbxMaterial->GetClassId().Is(FbxSurfaceLambert::ClassId))
			{
				FbxSurfaceLambert* lambertMaterial = (FbxSurfacePhong*)fbxMaterial;

				newMaterial.ambient = math::Vec3f(	lambertMaterial->Ambient.Get()[0],
													lambertMaterial->Ambient.Get()[1],
													lambertMaterial->Ambient.Get()[2]);

				newMaterial.diffuse = math::Vec3f(	lambertMaterial->Diffuse.Get()[0],
													lambertMaterial->Diffuse.Get()[1],
													lambertMaterial->Diffuse.Get()[2]);

				newMaterial.specular = math::Vec3f(	lambertMaterial->Emissive.Get()[0],
													lambertMaterial->Emissive.Get()[1],
													lambertMaterial->Emissive.Get()[2]);

				newMaterial.shininess = 0;
			}

			FbxProperty textureProperty = fbxMaterial->FindProperty(FbxSurfaceMaterial::sDiffuse);
			FbxFileTexture* texture		= FbxCast<FbxFileTexture>(textureProperty.GetSrcObject<FbxTexture>(0));
			if (texture)
				ParseTexture(texture, newMaterial);

			return GeneratePADMaterial(_outputPath, newMaterial);
		}
	}
	return NULL;
}

std::string GeneratePADMaterial(const	std::string&	_outputPath,
										AssetMaterial&	_material)
{
	std::string resultFile;

	resultFile	+=	"[AMBIENT]\n"
				+	std::to_string(_material.ambient.x)		+ " "
				+	std::to_string(_material.ambient.y)		+ " "
				+	std::to_string(_material.ambient.z)		+ "\n"
				+	"[DIFFUSE]\n"
				+	std::to_string(_material.diffuse.x)		+ " "
				+	std::to_string(_material.diffuse.y)		+ " "
				+	std::to_string(_material.diffuse.z)		+ "\n"
				+	"[SPECULAR]\n"
				+	std::to_string(_material.specular.x)	+ " "
				+	std::to_string(_material.specular.y)	+ " "
				+	std::to_string(_material.specular.z)	+ "\n"
				+	"[SHININESS]\n"
				+	std::to_string(_material.shininess)		+ "\n"
				+	"[TEXTURE_WRAP]\n"
				+	std::to_string(static_cast<unsigned int>(_material.textureParam.sWrap))	+ " "
				+	std::to_string(static_cast<unsigned int>(_material.textureParam.tWrap)) + "\n"
				+	"[TEXTURE_FILE]\n"
				+	PathFindFileName(_material.textureFile.c_str()) + "\n"
                +   "[CHANNEL]" + "\n"
                +   std::to_string(static_cast<unsigned int>(gfx::rhi::ChannelType::RGB));


	std::string outputFile = _outputPath + _material.name + ".PADMaterial";
	std::ofstream out(outputFile);
	out << resultFile;
	out.close();

	if (_material.textureFile.size() > 0)
	{		
		std::string textureOut = _outputPath + PathFindFileName(_material.textureFile.c_str());

		std::ifstream  source(_material.textureFile, std::ios::binary);
		std::ofstream  destination(textureOut, std::ios::binary);

		destination << source.rdbuf();
	}

	return outputFile;
}

void ParseBoneWeight(	const	std::string&			_outputPath,
						const	std::string&			_fileName,
								FbxScene*		const	_scene,
								FbxNode*		const	_currentNode,
								FbxMesh*		const	_fbxMesh,
								SkeletonData*	const	_skeleton,
								ControlPoint*	const	_controlPoint)
{
	unsigned int deformerCount = _fbxMesh->GetDeformerCount();
	unsigned int animCount = _scene->GetSrcObjectCount<FbxAnimStack>();

	FbxAMatrix geoTrans(_currentNode->GetGeometricTranslation(FbxNode::eSourcePivot),
						_currentNode->GetGeometricRotation(FbxNode::eSourcePivot),
						_currentNode->GetGeometricScaling(FbxNode::eSourcePivot));

	Anim** anims = new Anim*[animCount];
	for (int i = 0; i < animCount; ++i)
	{
		anims[i] = new Anim();
		anims[i]->boneInfos = nullptr;
	}

	for (unsigned int deformerIndex = 0; deformerIndex < deformerCount; ++deformerIndex)
	{
		FbxSkin* fbxSkin = reinterpret_cast<FbxSkin*>(_fbxMesh->GetDeformer(deformerIndex, FbxDeformer::eSkin));
		if (fbxSkin)
		{
			unsigned int clusterCount = fbxSkin->GetClusterCount();

			for (int clusterIndex = 0; clusterIndex < clusterCount; ++clusterIndex)
			{
				FbxCluster* fbxCluster = fbxSkin->GetCluster(clusterIndex);
				if (fbxCluster)
				{
					std::string boneName = fbxCluster->GetLink()->GetName();
					std::replace(boneName.begin(), boneName.end(), '/', '_');
					std::replace(boneName.begin(), boneName.end(), '\\', '_');
					int boneIndex = _skeleton->GetBoneIndex(boneName);
					if (boneIndex != -1)
					{
						FbxAMatrix transformMatrix;
						FbxAMatrix transformLinkMatrix;
						FbxAMatrix globalBindposeInverseMatrix;
						fbxCluster->GetTransformMatrix(transformMatrix);
						fbxCluster->GetTransformLinkMatrix(transformLinkMatrix);
						globalBindposeInverseMatrix = transformLinkMatrix.Inverse() * transformMatrix * geoTrans;

						_skeleton->bones[boneIndex]->inverseBindPose = FbxMatToMat(globalBindposeInverseMatrix);

						int		controlPointCount	= fbxCluster->GetControlPointIndicesCount();
						double* weight				= fbxCluster->GetControlPointWeights();
						int*	indices				= fbxCluster->GetControlPointIndices();

						for (int controlPointIndex = 0; controlPointIndex < controlPointCount; ++controlPointIndex)
						{
							for (int myCP = 0; myCP < _controlPoint->fbxIndicesMyIndice[indices[controlPointIndex]].size(); ++myCP)
							{
								_controlPoint->weightInfos[_controlPoint->fbxIndicesMyIndice[indices[controlPointIndex]][myCP]].boneIndex.push_back(boneIndex);
								_controlPoint->weightInfos[_controlPoint->fbxIndicesMyIndice[indices[controlPointIndex]][myCP]].weight.push_back(weight[controlPointIndex]);
							}
						}

						for (int animStackIndex = 0; animStackIndex < animCount; ++animStackIndex)
						{
							FbxAnimStack*	animStack	= _scene->GetSrcObject<FbxAnimStack>(animStackIndex);

							FbxTakeInfo*	takeInfo	= _scene->GetTakeInfo(animStack->GetName());
							FbxTime			start		= takeInfo->mLocalTimeSpan.GetStart();
							FbxTime			end			= takeInfo->mLocalTimeSpan.GetStop();
							int				lenght		= end.GetFrameCount(FbxTime::eFrames24) - start.GetFrameCount(FbxTime::eFrames24) + 1;

							if (!anims[animStackIndex]->boneInfos)
								anims[animStackIndex]->boneInfos = new BoneInfo[lenght];

							anims[animStackIndex]->frameNumber	= lenght;
							anims[animStackIndex]->name			= animStack->GetName();

							for (int frameIndex = start.GetFrameCount(FbxTime::eFrames24); frameIndex <= end.GetFrameCount(FbxTime::eFrames24); ++frameIndex)
							{
								FbxTime time;
								time.SetFrame(frameIndex, FbxTime::eFrames24);

								FbxAMatrix offset = _currentNode->EvaluateGlobalTransform(time) * geoTrans;
								anims[animStackIndex]->boneInfos[frameIndex].boneIds.push_back(boneIndex);
								anims[animStackIndex]->boneInfos[frameIndex].transforms.push_back(FbxMatToMat(offset.Inverse() * fbxCluster->GetLink()->EvaluateGlobalTransform(time)));
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < _fbxMesh->GetPolygonVertexCount(); ++i)
	{
		for (int j = _controlPoint->weightInfos[i].boneIndex.size(); j <= 3; ++j)
		{
			_controlPoint->weightInfos[i].boneIndex.push_back(-1);
			_controlPoint->weightInfos[i].weight.push_back(0);
		}
	}

	std::string append = "[BONE_WEIGHT]\n";
	for (int i = 0; i < _fbxMesh->GetPolygonVertexCount(); ++i)
	{
		for (int x = 0; x < _controlPoint->weightInfos[i].boneIndex.size(); ++x)
		{
			append += std::to_string(_controlPoint->weightInfos[i].boneIndex[x]) + " " + std::to_string(_controlPoint->weightInfos[i].weight[x]) + "\n";
		}
	}
	std::string meshFile = _outputPath + _fileName + ".PADMesh";
	std::ofstream out;
	out.open(meshFile, std::ios_base::app);
	out << append;

	if (animCount > 0)
		GeneratePADAnim(_outputPath, anims, animCount);
}

void ParseTexture(	FbxFileTexture* const	_texture, 
					AssetMaterial&			_material)
{
	_material.textureFile = _texture->GetFileName();

	if (_texture->GetWrapModeU() == FbxTexture::EWrapMode::eRepeat)
		_material.textureParam.sWrap = gfx::rhi::E_WRAP_TYPE::REPEAT;
	else
		_material.textureParam.sWrap = gfx::rhi::E_WRAP_TYPE::CLAMP_EDGE;

	if (_texture->GetWrapModeV() == FbxTexture::EWrapMode::eRepeat)
		_material.textureParam.tWrap = gfx::rhi::E_WRAP_TYPE::REPEAT;
	else
		_material.textureParam.tWrap = gfx::rhi::E_WRAP_TYPE::CLAMP_EDGE;
}

void GeneratePADAnim(	const	std::string&			_outputPath,
								Anim**			const	_anims,
						const	int						_animCount)
{
	for (int animIndex = 0; animIndex < _animCount; ++animIndex)
	{
		std::string result;

		for (int frameIndex = 0; frameIndex < _anims[animIndex]->frameNumber; ++frameIndex)
		{
			result += "[KEY]" + std::to_string(frameIndex) + "\n";
			result += std::to_string(_anims[animIndex]->boneInfos[frameIndex].boneIds.size()) + "\n";

			for (int boneIndex = 0; boneIndex < _anims[animIndex]->boneInfos[frameIndex].boneIds.size(); ++boneIndex)
			{
				result += std::to_string(_anims[animIndex]->boneInfos[frameIndex].boneIds[boneIndex]) + " ";
				result += MatToString(_anims[animIndex]->boneInfos[frameIndex].transforms[boneIndex]) + "\n";
			}
		}

		std::string animFile = _outputPath + _anims[animIndex]->name + ".PADAnim";
		std::ofstream out(animFile);
		out << result;
		out.close();
	}

}

math::Mat4 FbxMatToMat(const FbxAMatrix& _matrix)
{
	return math::Mat4(	_matrix.mData[0][0],
						_matrix.mData[0][1],
						_matrix.mData[0][2],
						_matrix.mData[0][3],
						_matrix.mData[1][0],
						_matrix.mData[1][1],
						_matrix.mData[1][2],
						_matrix.mData[1][3],
						_matrix.mData[2][0],
						_matrix.mData[2][1],
						_matrix.mData[2][2],
						_matrix.mData[2][3],
						_matrix.mData[3][0],
						_matrix.mData[3][1],
						_matrix.mData[3][2],
						_matrix.mData[3][3]);
}

std::string MatToString(const math::Mat4 & _matrix)
{
	std::string result;

	for (int i = 0; i < 16; ++i)
		result += std::to_string(_matrix[i / 4][i % 4]) + " ";

	return result;
}

} // namespace parser
} // namespace pad