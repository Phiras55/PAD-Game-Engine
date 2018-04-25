#pragma once

#include <System/Resource/ResourceManager.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/Model/Material.h>

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
	ResourceManager<gfx::mod::Material>		m_materialManager;

public:
	ResourceManager<gfx::mod::Mesh>&			GetMeshManager()			{ return m_meshManager; }
	const ResourceManager<gfx::mod::Mesh>&		GetMeshManager() const		{ return m_meshManager; }
	ResourceManager<gfx::mod::Material>&		GetMaterialManager()		{ return m_materialManager; }
	const ResourceManager<gfx::mod::Material>&	GetMaterialManager() const	{ return m_materialManager; }
};

} // namespace res
} // namespace sys
} // namespace pad