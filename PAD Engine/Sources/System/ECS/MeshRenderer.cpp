#include <EnginePCH.h>
#include <System/ECS/MeshRenderer.h>
#include <System/ECS/PADObject.h>

namespace pad	{
namespace sys	{
namespace ecs	{

alias::ComponentID MeshRenderer::m_id = INVALID_COMPONENT_ID;

MeshRenderer::MeshRenderer() :
	m_meshName(),
	m_materialName()
{
	if(m_id != INVALID_COMPONENT_ID)
		m_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
}

MeshRenderer::MeshRenderer(const MeshRenderer& _other)
{
	m_meshName		= _other.m_meshName;
	m_materialName	= _other.m_materialName;
	m_settings		= _other.m_settings;
}

MeshRenderer::MeshRenderer(const std::string& _meshName, const std::string& _materialName):
	MeshRenderer()
{
	m_meshName		= _meshName;
	m_materialName	= _materialName;
}

MeshRenderer::~MeshRenderer()
{
	
}

void MeshRenderer::Init()
{
	m_settings.modelMatrix = &m_owner->GetTransform().GetGlobalTransform();
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
	m_meshName =			JsonToData<std::string>(j, "m_meshName");
	m_materialName =		JsonToData<std::string>(j, "m_materialName");
	m_settings.Deserialize(	JsonToData<json>(j, "m_settings"));
}

void MeshRenderer::operator=(const MeshRenderer& _other)
{
	m_meshName		= _other.m_meshName;
	m_materialName	= _other.m_materialName;
	m_settings		= _other.m_settings;
}

} // namespace ecs
} // namespace sys
} // namespace pad