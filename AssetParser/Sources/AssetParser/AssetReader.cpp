#include <iostream>
#include <fstream>
#include <sstream>
#include <AssetParser/AssetReader.h>
#include <Shlwapi.h>

#pragma comment(lib,"shlwapi.lib")

namespace pad		{
namespace parser	{

void ReadPADMesh(const	std::string&			_inputPath, 
						gfx::mod::MeshData&		_meshData)
{
	enum SECTION
	{
		VERTEX_COUNT,
		INDICE_COUNT,
		MATERIAL,
		POINTS,
		NORMALS,
		UVS,
		INDICES,
		BONE_WEIGHT,
		DEFAULT
	};

	int pointCounter	= 0;
	int normalCounter	= 0;
	int uvCounter		= 0;
	int indicesCounter	= 0;
	int boneCounter		= 0;
	SECTION sec			= DEFAULT;

	std::ifstream in(_inputPath);
	std::string line;
	while (std::getline(in, line))
	{
		std::istringstream stream(line);
		if (line[0] == '[')
		{
			if (line == "[VERTEX_COUNT]")
				sec = VERTEX_COUNT;
			else if (line == "[INDICE_COUNT]")
				sec = INDICE_COUNT;
			else if (line == "[MATERIAL]")
				sec = MATERIAL;
			else if (line == "[POINTS]")
				sec = POINTS;
			else if (line == "[NORMALS]")
				sec = NORMALS;
			else if (line == "[UVS]")
				sec = UVS;
			else if (line == "[INDICES]")
				sec = INDICES;
			else if (line == "[BONE_WEIGHT]")
				sec = BONE_WEIGHT;
			else
				sec = DEFAULT;
		}
		else
		{
			switch (sec)
			{
				case VERTEX_COUNT :
				{
					stream >> _meshData.positionCount;

					_meshData.normalCount	= _meshData.positionCount * 3;
					_meshData.uvCount		= _meshData.positionCount * 2;

					_meshData.positions		= new float[_meshData.positionCount * 3];
					_meshData.normals		= new float[_meshData.normalCount * 3];
					_meshData.uvs			= new float[_meshData.uvCount * 2];
					_meshData.boneIndex		= new int[_meshData.positionCount * 4];
					_meshData.weight		= new float[_meshData.positionCount * 4];

					_meshData.positionCount *= 3;

					break;
				}
				case INDICE_COUNT :
				{
					stream >> _meshData.indiceCount;
					_meshData.indices = new uint32[_meshData.indiceCount];
					break;
				}
				case POINTS :
				{
					stream >> _meshData.positions[pointCounter] >> _meshData.positions[pointCounter + 1] >> _meshData.positions[pointCounter + 2];
					pointCounter += 3;
					break;
				}
				case NORMALS :
				{
					stream >> _meshData.normals[normalCounter] >> _meshData.normals[normalCounter + 1] >> _meshData.normals[normalCounter + 2];
					normalCounter += 3;
					break;
				}
				case UVS :
				{
					stream >> _meshData.uvs[uvCounter] >> _meshData.uvs[uvCounter + 1];
					uvCounter += 2;
					break;
				}
				case INDICES :
				{
					stream >> _meshData.indices[indicesCounter] >> _meshData.indices[indicesCounter + 1] >> _meshData.indices[indicesCounter + 2];
					indicesCounter += 3;
					break;
				}
				case MATERIAL :
				{
					std::string path;
					stream >> path;
//					ReadPADMaterial(path);
				}
				case BONE_WEIGHT :
				{
					stream >> _meshData.boneIndex[boneCounter] >> _meshData.weight[boneCounter];
					++boneCounter;
					break;
				}
			}
		}
	}
}

void ReadPADMaterial(const	std::string&			_inputPath,
							gfx::mod::MaterialData&	_materialData,
							gfx::mod::TextureData&	_textureData)
{
	enum SECTION
	{
		AMBIENT,
		DIFFUSE,
		SPECULAR,
		SHININESS,
		TEXTURE_FILE,
		TEXTURE_WRAP,
		CHANNEL,
		DEFAULT
	};

	SECTION sec = DEFAULT;

	std::string	name		= PathFindFileName(_inputPath.c_str());
	_materialData.m_name	= name.substr(0, name.find_last_of("."));

	std::ifstream in(_inputPath);
	std::string line;
	while (std::getline(in, line))
	{
		std::istringstream stream(line);
		if (line[0] == '[')
		{
			if (line == "[AMBIENT]")
				sec = AMBIENT;
			else if (line == "[DIFFUSE]")
				sec = DIFFUSE;
			else if (line == "[SPECULAR]")
				sec = SPECULAR;
			else if (line == "[SHININESS]")
				sec = SHININESS;
			else if (line == "[TEXTURE_WRAP]")
				sec = TEXTURE_WRAP;
			else if (line == "[TEXTURE_FILE]")
				sec = TEXTURE_FILE;
			else if (line == "[CHANNEL]")
				sec = CHANNEL;
			else
				sec = DEFAULT;
		}
		else
		{
			switch (sec)
			{
				case AMBIENT:
				{
					stream >> _materialData.m_ambient.x >> _materialData.m_ambient.y >> _materialData.m_ambient.z;
					break;
				}
				case DIFFUSE:
				{
					stream >> _materialData.m_diffuse.x >> _materialData.m_diffuse.y >> _materialData.m_diffuse.z;
					break;
				}
				case SPECULAR:
				{
					stream >> _materialData.m_specular.x >> _materialData.m_specular.y >> _materialData.m_specular.z;
					break;
				}
				case SHININESS:
				{
					stream >> _materialData.m_shiness;
					break;
				}
				case TEXTURE_WRAP:
				{
					stream >> _textureData.m_sWrap >> _textureData.m_tWrap;
					break;
				}
				case TEXTURE_FILE:
				{
					std::string textureName;
					stream >> textureName;

					std::string texturePath = _inputPath.substr(0, _inputPath.find_last_of("\\/"));
					texturePath += "\\" + textureName;

					_textureData.m_name		= textureName.substr(0, textureName.find_last_of("."));
					_textureData.m_path		= texturePath;

					break;
				}
				case CHANNEL:
				{
					stream >> _textureData.m_channel;
					break;
				}
			}
		}
	}
}

void ReadPADSkeleton(const	std::string&		_inputPath, 
							sys::ecs::Skeleton& _skeleton)
{
	enum SECTION
	{
		BONE_COUNT,
		BONES,
		DEFAULT
	};

	SECTION sec = DEFAULT;

//	std::string	name = PathFindFileName(_inputPath.c_str());
	_skeleton.SetName(GetFileNameNoExt(_inputPath));

	std::ifstream in(_inputPath);
	std::string line;
	while (std::getline(in, line))
	{
		std::istringstream stream(line);
		if (line[0] == '[')
		{
			if (line == "[BONE_COUNT]")
				sec = BONE_COUNT;
			else if (line == "[BONES]")
				sec = BONES;
		}
		else
		{
			switch (sec)
			{
				case BONE_COUNT:
				{
					int boneCount;
					stream >> boneCount;
					_skeleton.SetBoneCount(boneCount);
					break;
				}
				case BONES:
				{
					sys::ecs::Bone b;
					stream	>> b.m_name >> b.m_id >> b.m_parentId 
							>> b.m_inverseBindPose[0][0] >> b.m_inverseBindPose[0][1] >> b.m_inverseBindPose[0][2] >> b.m_inverseBindPose[0][3]
							>> b.m_inverseBindPose[1][0] >> b.m_inverseBindPose[1][1] >> b.m_inverseBindPose[1][2] >> b.m_inverseBindPose[1][3] 
							>> b.m_inverseBindPose[2][0] >> b.m_inverseBindPose[2][1] >> b.m_inverseBindPose[2][2] >> b.m_inverseBindPose[2][3]
							>> b.m_inverseBindPose[3][0] >> b.m_inverseBindPose[3][1] >> b.m_inverseBindPose[3][2] >> b.m_inverseBindPose[3][3];
					_skeleton.AddBone(b);
					break;
				}
			}
		}
	}
}

std::string GetFileExt(const std::string& _path)
{
	return PathFindExtension(_path.c_str());
}

std::string GetFileName(const std::string& _path)
{
	return PathFindFileName(_path.c_str());
}

std::string GetFileNameNoExt(const std::string& _path)
{
	std::string result;
	result			= GetFileName(_path);
	size_t extIndex = result.find_last_of(".");
	result			= result.substr(0, extIndex);
	return result;
}

} // namespace parser
} // namespace pad