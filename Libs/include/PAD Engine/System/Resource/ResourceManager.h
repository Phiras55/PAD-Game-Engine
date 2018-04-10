#pragma once

#include <System/Resource/MeshManager.h>

namespace pad	{
namespace sys	{
namespace res	{

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

private:
	MeshManager			m_meshManager;
//	MaterialManager		m_materialManager;
//	TextureManager		m_textureManager;

public:
	MeshManager& GetMeshManager() { return m_meshManager; }
};

} // namespace res
} // namespace sys
} // namespace pad