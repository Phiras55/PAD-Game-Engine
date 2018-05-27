#include <EnginePCH.h>
#include <System/ECS/DirectionalLight.h>

namespace pad	{
namespace sys	{
namespace ecs	{

alias::ComponentID DirectionalLight::m_id = INVALID_COMPONENT_ID;

DirectionalLight::DirectionalLight()
{
	if (m_id != INVALID_COMPONENT_ID)
		m_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
}

DirectionalLight::DirectionalLight(const DirectionalLight& _other)
{
	if (m_id != INVALID_COMPONENT_ID)
		m_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());

	m_color		= _other.m_color;
	m_intensity = _other.m_intensity;
}

DirectionalLight::~DirectionalLight()
{

}

void DirectionalLight::Init()
{

}

void DirectionalLight::Start()
{

}

void DirectionalLight::Update()
{

}

void DirectionalLight::FixedUpdate()
{

}

void DirectionalLight::LateUpdate()
{

}

json DirectionalLight::Serialize()
{
	json j;

	AddDataToJson(j, "m_color",		m_color.Serialize());
	AddDataToJson(j, "m_intensity", m_intensity);

	return j;
}

void DirectionalLight::Deserialize(const json& j)
{
	m_color.Deserialize(JsonToData<json>(j, "m_color"));
	m_intensity = JsonToData<float>(j, "m_intensity");
}

void DirectionalLight::operator=(const DirectionalLight& _other)
{
	m_color		= _other.m_color;
	m_intensity = _other.m_intensity;
}

} // namespace ecs
} // namespace sys
} // namespace pad