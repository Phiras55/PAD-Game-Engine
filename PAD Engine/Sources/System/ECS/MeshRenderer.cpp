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

json MeshRenderer::Serialize()
{
	json j;

	AddDataToJson(j, "m_meshName", m_meshName);
	AddDataToJson(j, "m_materialName", m_materialName);
	AddDataToJson(j, "m_settings", m_settings.Serialize());

	return j;
}

void MeshRenderer::Deserialize(const json& j)
{
	m_meshName		= JsonToData<std::string>(j, "m_meshName");
	m_materialName	= JsonToData<std::string>(j, "m_materialName");
	m_settings.Deserialize(JsonToData<json>(j, "m_settings"));
}

} // namespace ecs
} // namespace sys
} // namespace pad