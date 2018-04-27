#include <EnginePCH.h>
#include <System/ECS/MeshRenderer.h>

namespace pad	{
namespace sys	{
namespace ecs	{

std::vector<MeshRenderer> MeshRenderer::m_collection;

MeshRenderer::MeshRenderer(math::Transform& _ownerTransform)
{
	m_type = COMPONENT_TYPE::MESH_RENDERER;
	m_settings.modelMatrix = &_ownerTransform.GetLocalTransform();
}

MeshRenderer::~MeshRenderer()
{

}

void MeshRenderer::Init(PADObject* const _owner)
{

}

void MeshRenderer::Start()
{

}

void MeshRenderer::Update()
{

}

void MeshRenderer::FixedUpdate()
{

}

void MeshRenderer::LateUpdate()
{

}

void MeshRenderer::AddToCollection(const MeshRenderer& _meshRenderer)
{
	m_collection.push_back(_meshRenderer);
}

} // namespace ecs
} // namespace sys
} // namespace pad