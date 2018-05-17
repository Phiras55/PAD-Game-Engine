#pragma once

#include <PADRenderer/Common.h>
#include <PADRenderer/Graphics/Model/MaterialData.h>
#include <PADRenderer/Graphics/Model/MeshData.h>
#include <PADRenderer/Graphics/Model/TextureData.h>
#include <PAD Engine/System/ECS/Skeleton.h>

#include <string>

namespace pad		{
namespace parser	{

void ReadPADMesh(const	std::string&			_inputPath, 
						gfx::mod::MeshData&		_meshData);

void ReadPADMaterial(	const	std::string&			_inputPath,
								gfx::mod::MaterialData&	_materialData,
								gfx::mod::TextureData&	_textureData);

void ReadPADSkeleton(	const	std::string&		_inputPath,
								sys::ecs::Skeleton& _skeleton);

std::string GetFileExt(const std::string& _path);
std::string GetFileName(const std::string& _path);
std::string GetFileNameNoExt(const std::string& _path);

} // namespace parser
} // namespace pad