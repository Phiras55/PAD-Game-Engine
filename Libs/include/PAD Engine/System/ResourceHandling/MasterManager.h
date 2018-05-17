#pragma once
#include <System/ResourceHandling/ResourceManager.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/Model/Material.h>
#include <Graphics/RHI/ATexture.h>
#include <Graphics/Model/Skeleton.h>

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
	ResourceManager<gfx::rhi::ATexture*>	m_textureManager;
	ResourceManager<gfx::mod::Skeleton>		m_skeletonManager;

public:
	ResourceManager<gfx::mod::Mesh>&			GetMeshManager()			{ return m_meshManager; }
	const ResourceManager<gfx::mod::Mesh>&		GetMeshManager() const		{ return m_meshManager; }
	ResourceManager<gfx::mod::Material>&		GetMaterialManager()		{ return m_materialManager; }
	const ResourceManager<gfx::mod::Material>&	GetMaterialManager() const	{ return m_materialManager; }
	ResourceManager<gfx::rhi::ATexture*>&		GetTextureManager()			{ return m_textureManager; }
	const ResourceManager<gfx::rhi::ATexture*>&	GetTextureManager() const	{ return m_textureManager; }
	ResourceManager<gfx::mod::Skeleton>&		GetSkeletonManager()		{ return m_skeletonManager; }
	const ResourceManager<gfx::mod::Skeleton>&	GetSkeletonManager() const	{ return m_skeletonManager; }
};

} // namespace res
} // namespace sys
} // namespace pad