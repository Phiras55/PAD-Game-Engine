#pragma once

#include <System/ECS/IComponent.h>

#include <Utilities/Export.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API AScriptComponent : public IComponent
{
protected:
	AScriptComponent();
public:
	virtual	~AScriptComponent();
	
	void SetOwner(PADObject* const _owner)	override		{ m_owner = _owner; }
	PADObject* const GetOwner() const		override		{ return m_owner; }

	virtual const COMPONENT_TYPE GetType() const override	{ return m_type; }
};

} // namespace ecs
} // namespace sys
} // namespace pad