#include <System/ECS/AScriptComponent.h>

namespace pad	{
namespace sys	{
namespace ecs	{

std::vector<AScriptComponent*> AScriptComponent::m_collection;

AScriptComponent::AScriptComponent()
{
	m_type = SCRIPT;
}

AScriptComponent::~AScriptComponent()
{

}

void AScriptComponent::Init()
{
	m_collection.push_back(this);
}

void AScriptComponent::ScriptUpdate()
{
	for (auto script : m_collection)
		script->Update();
}

} // namespace ecs
} // namespace sys
} // namespace pad