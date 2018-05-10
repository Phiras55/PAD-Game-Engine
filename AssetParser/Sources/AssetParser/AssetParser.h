#pragma once

#include <Math/Transform.h>
#include <fbxsdk.h>
#include <string>
#include <vector>
#include <PADRenderer/Graphics/RHI/TextureParameters.h>

#define ASSET_PARSER_EXPORTS
#ifdef ASSET_PARSER_EXPORTS 
#define ASSET_PARSER_API __declspec(dllexport)   
#else  
#define ASSET_PARSER_API __declspec(dllimport)
#endif

namespace pad		{
namespace parser	{

enum PARSER_RESULT
{
	SUCCESS,
	FAILURE,
	DEFAULT
};

struct AssetMaterial
{
	math::Vec3f	ambient;
	math::Vec3f	diffuse;
	math::Vec3f	specular;
	float		shininess;

	std::string					name;
	std::string					textureFile;
	gfx::rhi::TextureParameters textureParam;
};

struct Bone
{
	int				id;
	int				parentId;
	std::string		boneName;

	math::Quat		rotation;
	math::Vec4f		translation;
	math::Vec4f		scale;

	math::Mat4		inverseBindPose;
};

struct Skeleton
{
	std::string			skeletonName;
	std::vector<Bone*>	bones;

	~Skeleton()
	{
		for (int boneIndex = 0; boneIndex < bones.size(); ++boneIndex)
		{
			delete bones[boneIndex];
		}
	}

	int GetBoneIndex(const std::string _boneName)
	{
		for (int boneIndex = 0; boneIndex < bones.size(); ++boneIndex)
		{
			if (bones[boneIndex]->boneName == _boneName)
				return boneIndex;
		}
		return -1;
	}
};

PARSER_RESULT ParseFile(const	std::string& _inputPath, 
						const	std::string& _outputPath);

PARSER_RESULT ParseFBX(	const	std::string& _inputPath, 
						const	std::string& _outputPath,
								std::string& _fileName);

void ParseMesh(			FbxNode*		const	_node,
				const	std::string&			_outputPath,
						std::string&			_fileName);

void ParseNormals(	int									_index,
					int									_polygonIndiceStart,
					FbxGeometryElementNormal*	const	_normalsRaw,
					int*						const	_indices,
					FbxVector4*					const	_normals);

void ParseUV(	int								_index, 
				FbxGeometryElementUV*	const	_fbxUVs, 
				int*					const	_indices, 
				FbxVector2*				const	_uvs);

void GeneratePADMesh(	const	std::string&			_outputPath,
						const	int						_indicesCount,
								int*			const	_indices,
								FbxVector4*		const	_vertex,
								FbxVector4*		const	_normals,
								FbxVector2*		const	_uvs,
						const	std::string&			_materialPath);

void ParseSkeleton(	FbxNode*		const	_currentNode,
					Skeleton*		const	_skeleton);

void ParseSkeletonRecur(Skeleton*	const	_skeleton,
						FbxNode*	const	_currentNode,
						int					_id,
						int					_parentId);

void GeneratePADSkeleton(	const	std::string&			_outputPath, 
							const	std::string&			_skeletonName,
									Skeleton*		const	_skeleton);

std::string ParseMaterial(const	std::string&			_outputPath,
								FbxNode*		const	_currentNode);

std::string GeneratePADMaterial(const	std::string&	_outputPath, 
										AssetMaterial&	_material);

void ParseAnimation(FbxNode*	const	_currentNode,
					FbxMesh*	const	_fbxMesh,
					Skeleton*	const	_skeleton);

void ParseTexture(	FbxFileTexture*	const	_texture,
					AssetMaterial&			_material);

math::Mat4 FbxMatToMat(const FbxAMatrix& _matrix);

} // namespace parser
} // namespace pad