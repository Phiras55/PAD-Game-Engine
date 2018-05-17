#pragma once

#include <Math/Transform.h>
#include <fbxsdk.h>
#include <string>
#include <vector>
#include <unordered_map>
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

struct WeightInfo
{
	std::vector<int>	boneIndex;
	std::vector<float>	weight;
};

struct ControlPoint
{
	std::unordered_map<int, std::vector<int>> fbxIndicesMyIndice;
	WeightInfo* weightInfos;
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

struct BoneData
{
	int				id;
	int				parentId;
	std::string		boneName;

	math::Quat		rotation;
	math::Vec4f		translation;
	math::Vec4f		scale;

	math::Mat4		inverseBindPose;
};

struct SkeletonData
{
	std::string				skeletonName;
	std::vector<BoneData*>	bones;

	~SkeletonData()
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

struct BoneInfo
{
	std::vector<int>		boneIds;
	std::vector<math::Mat4> transforms;
};

struct Anim
{
	std::string		name;
	int				frameNumber;
	float			animDuration;
	BoneInfo*		boneInfos;
};

PARSER_RESULT ParseFile(const	std::string& _inputPath, 
						const	std::string& _outputPath);

PARSER_RESULT ParseFBX(	const	std::string& _inputPath, 
						const	std::string& _outputPath,
								std::string& _fileName);

void ParseMesh(			FbxNode*		const	_node,
				const	std::string&			_outputPath,
				const	std::string&			_fileName,
						ControlPoint*			_controlPoint);

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
					SkeletonData*	const	_skeleton);

void ParseSkeletonRecur(SkeletonData*	const	_skeleton,
						FbxNode*		const	_currentNode,
						int						_id,
						int						_parentId);

void GeneratePADSkeleton(	const	std::string&			_outputPath, 
							const	std::string&			_skeletonName,
									SkeletonData*	const	_skeleton);

std::string ParseMaterial(const	std::string&			_outputPath,
								FbxNode*		const	_currentNode);

std::string GeneratePADMaterial(const	std::string&	_outputPath, 
										AssetMaterial&	_material);

void ParseBoneWeight(	const	std::string&			_outputPath,
						const	std::string&			_fileName,
								FbxScene*		const	_scene,
								FbxNode*		const	_currentNode,
								FbxMesh*		const	_fbxMesh,
								SkeletonData*	const	_skeleton,
								ControlPoint*	const	_controlPoint);

void ParseTexture(	FbxFileTexture*	const	_texture,
					AssetMaterial&			_material);

void GeneratePADAnim(	const	std::string&			_outputPath,
								Anim**			const	_anims,
						const	int						_animCount);

math::Mat4 FbxMatToMat(	const FbxAMatrix& _matrix);

std::string MatToString(const math::Mat4& _matrix);

} // namespace parser
} // namespace pad