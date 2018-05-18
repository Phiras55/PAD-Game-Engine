#include <EnginePCH.h>
#include <System/ECS/AnimRenderer.h>
#include <Core/Engine.h>

namespace pad	{
namespace sys	{
namespace ecs	{

alias::ComponentID AnimRenderer::m_AR_id = INVALID_COMPONENT_ID;

AnimRenderer::AnimRenderer()
{
	if (m_AR_id != INVALID_COMPONENT_ID)
		m_AR_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
}

AnimRenderer::AnimRenderer(const AnimRenderer& _other)
{
	m_meshName			= _other.m_meshName;
	m_materialName		= _other.m_materialName;
	m_settings			= _other.m_settings;
	m_skeletonName		= _other.m_skeletonName;
	m_currentAnim		= _other.m_currentAnim;
	m_currentKey		= _other.m_currentKey;
	m_keyFrameDuration	= _other.m_keyFrameDuration;
	m_animTimer			= _other.m_animTimer;
}

AnimRenderer::AnimRenderer(	const std::string&	_meshName, 
							const std::string&	_materialName, 
							const std::string&	_skeletonName,
							const std::string&	_animName)
{
	m_meshName		= _meshName;
	m_materialName	= _materialName;
	m_skeletonName	= _skeletonName;
	m_currentAnim	= _animName;
}

AnimRenderer::~AnimRenderer()
{
}

void AnimRenderer::Init()
{
	//m_meshP = 
}

void AnimRenderer::Start()
{
}

void AnimRenderer::Update()
{
}

void AnimRenderer::FixedUpdate()
{
}

void AnimRenderer::LateUpdate()
{
}

json AnimRenderer::Serialize()
{
	json j;

	AddDataToJson(j, "m_meshName", m_meshName);
	AddDataToJson(j, "m_materialName", m_materialName);
	AddDataToJson(j, "m_settings", m_settings.Serialize());
	AddDataToJson(j, "m_skeletonName", m_skeletonName);
	AddDataToJson(j, "m_currentAnim", m_currentAnim);

	return j;
}

void AnimRenderer::Deserialize(const json& j)
{
	m_meshName			= JsonToData<std::string>(j, "m_meshName");
	m_materialName		= JsonToData<std::string>(j, "m_materialName");
	m_skeletonName		= JsonToData<std::string>(j, "m_skeletonName");
	m_currentAnim		= JsonToData<std::string>(j, "m_currentAnim");

	m_settings.Deserialize(JsonToData<json>(j, "m_settings"));
}

void AnimRenderer::operator=(const AnimRenderer& _other)
{
	m_meshName			= _other.m_meshName;
	m_materialName		= _other.m_materialName;
	m_settings			= _other.m_settings;
	m_skeletonName		= _other.m_skeletonName;
	m_currentAnim		= _other.m_currentAnim;
	m_currentKey		= _other.m_currentKey;
	m_keyFrameDuration	= _other.m_keyFrameDuration;
	m_animTimer			= _other.m_animTimer;
}

} // namespace ecs
} // namespace sys
} // namespace pad