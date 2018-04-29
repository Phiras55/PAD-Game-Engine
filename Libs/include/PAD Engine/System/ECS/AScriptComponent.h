#pragma once

#include <System/ECS/IComponent.h>

#include <Utilities/Export.h>
#include <vector>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API AScriptComponent : public IComponent
{
protected:
	AScriptComponent();
public:
	virtual	~AScriptComponent();

private:
	static std::vector<AScriptComponent*>	m_collection;

public:
	virtual void Init() override;

public:
	void SetOwner(PADObject* const _owner)	override { m_owner = _owner; }
	PADObject* const GetOwner() const		override { return m_owner; }

	virtual const COMPONENT_TYPE GetType() const override { return m_type; }

	static const std::vector<AScriptComponent*>& GetCollection() { return m_collection; }
	static void ScriptUpdate();
};

} // namespace ecs
} // namespace sys
} // namespace pad