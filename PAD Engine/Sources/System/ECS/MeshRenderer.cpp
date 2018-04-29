#include <EnginePCH.h>
#include <System/ECS/MeshRenderer.h>

namespace pad	{
namespace sys	{
namespace ecs	{

std::vector<MeshRenderer*> MeshRenderer::m_collection;

MeshRenderer::MeshRenderer()
{
	m_type					= COMPONENT_TYPE::MESH_RENDERER;
	m_settings.modelMatrix	= &m_transform.GetGlobalTransform();

	m_collection.push_back(this);
}

MeshRenderer::~MeshRenderer()
{

}

void MeshRenderer::Init()
{

}

void MeshRenderer::Start()
{
	m_transform.SetGlobalTransform(		m_owner->GetTransform().GetGlobalTransform()
									*	m_transform.GetLocalTransform());
}

void MeshRenderer::Update()
{
	m_transform.SetGlobalTransform(		m_owner->GetTransform().GetGlobalTransform()
									*	m_transform.GetLocalTransform());
}

void MeshRenderer::FixedUpdate()
{

}

void MeshRenderer::LateUpdate()
{

}

void MeshRenderer::AddToCollection(MeshRenderer* const _meshRenderer)
{
	m_collection.push_back(_meshRenderer);
}

} // namespace ecs
} // namespace sys
} // namespace pad