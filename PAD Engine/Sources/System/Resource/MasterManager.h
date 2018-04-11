#pragma once

#include <System/Resource/ResourceManager.h>
#include <Graphics/Model/Mesh.h>

namespace pad	{
namespace sys	{
namespace res	{

class MasterManager
{
public:
	MasterManager();
	~MasterManager();

private:
	ResourceManager<gfx::mod::Mesh>			m_meshManager;

public:
	ResourceManager<gfx::mod::Mesh>& GetMeshManager() { return m_meshManager; }
};

} // namespace res
} // namespace sys
} // namespace pad