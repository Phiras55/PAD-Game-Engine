#pragma once

#include <PADRenderer/Common.h>
#include <PADRenderer/Graphics/Model/MaterialData.h>
#include <PADRenderer/Graphics/Model/MeshData.h>
#include <PADRenderer/Graphics/Model/TextureData.h>
#include <PADRenderer/Graphics/Model/Skeleton.h>
#include <string>

namespace pad		{
namespace parser	{

void ReadPADMesh(const	std::string&			_inputPath, 
						gfx::mod::MeshData&		_meshData);

void ReadPADMaterial(	const	std::string&			_inputPath,
								gfx::mod::MaterialData&	_materialData,
								gfx::mod::TextureData&	_textureData);

void ReadPADSkeleton(	const	std::string&		_inputPath,
								gfx::mod::Skeleton&	_skeleton);

void ReadPADAnim(const	std::string&		_inputPath,
						gfx::mod::Anim&		_anim);

std::string GetFileExt(const std::string& _path);
std::string GetFileName(const std::string& _path);
std::string GetFileNameNoExt(const std::string& _path);

} // namespace parser
} // namespace pad