#pragma once

#include <System/ECS/IComponent.h>
#include <System/ECS/Collider.h>
#include <Utilities/Export.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API RigidBody final : public IComponent
{
public:
	RigidBody();
	~RigidBody();

public:
	void Init(PADObject* const _owner)	override;
	void Start()						override;
	void Update()						override;
	void FixedUpdate()					override;
	void LateUpdate()					override;

public:
	inline void SetMass(const float _mass);

	inline btRigidBody* const	GetBTRigidBody() const				{ return m_btRigidBody; }

	virtual void				SetOwner(PADObject* const _owner)	{ m_owner = _owner; }
	virtual PADObject* const	GetOwner() const					{ return m_owner; }

	virtual const COMPONENT_TYPE GetType() const override { return m_type; }

private:
	btRigidBody*	m_btRigidBody;
	btMotionState*	m_btMotionState;
	Collider*		m_collider;
};

} // namespace ecs
} // namespace sys
} // namespace pad