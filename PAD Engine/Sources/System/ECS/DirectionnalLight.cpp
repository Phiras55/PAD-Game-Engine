#include <EnginePCH.h>
#include <System/ECS/DirectionnalLight.h>

namespace pad	{
namespace sys	{
namespace ecs	{

alias::ComponentID DirectionnalLight::m_id = INVALID_COMPONENT_ID;

DirectionnalLight::DirectionnalLight()
{
	if (m_id != INVALID_COMPONENT_ID)
		m_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
}

DirectionnalLight::DirectionnalLight(const DirectionnalLight& _other)
{
	if (m_id != INVALID_COMPONENT_ID)
		m_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());

	m_color		= _other.m_color;
	m_intensity = _other.m_intensity;
}

DirectionnalLight::~DirectionnalLight()
{

}

void DirectionnalLight::Init()
{

}

void DirectionnalLight::Start()
{

}

void DirectionnalLight::Update()
{

}

void DirectionnalLight::FixedUpdate()
{

}

void DirectionnalLight::LateUpdate()
{

}

json DirectionnalLight::Serialize()
{
	json j;

	AddDataToJson(j, "m_color",		m_color.Serialize());
	AddDataToJson(j, "m_intensity", m_intensity);

	return j;
}

void DirectionnalLight::Deserialize(const json& j)
{
	m_color.Deserialize(JsonToData<json>(j, "m_color"));
	m_intensity = JsonToData<float>(j, "m_intensity");
}

void DirectionnalLight::operator=(const DirectionnalLight& _other)
{
	m_color		= _other.m_color;
	m_intensity = _other.m_intensity;
}

} // namespace ecs
} // namespace sys
} // namespace pad