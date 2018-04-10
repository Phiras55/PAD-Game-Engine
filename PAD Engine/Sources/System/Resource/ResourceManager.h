#pragma once

#include <System/Resource/AResourceManager.h>
#include <Graphics/Model/Mesh.h>

namespace pad	{
namespace sys	{
namespace res	{

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

private:
	AResourceManager<gfx::mod::Mesh>			m_meshManager;
//	MaterialManager		m_materialManager;
//	TextureManager		m_textureManager;

public:
	AResourceManager<gfx::mod::Mesh>& GetMeshManager() { return m_meshManager; }
};

} // namespace res
} // namespace sys
} // namespace pad