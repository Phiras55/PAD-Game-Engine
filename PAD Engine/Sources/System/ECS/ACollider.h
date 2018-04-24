#pragma once

#include <System/ECS/IComponent.h>
#include <Bullet/btBulletDynamicsCommon.h>
#include <Utilities/Export.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API ACollider : public IComponent
{
protected:
	ACollider();
public:
	virtual ~ACollider();

	void Init()	override;

public:
	btCollisionObject* const	GetBTCollider() const			{ return m_btCollider; }
	btCollisionShape* const		GetBTCollisionShape() const		{ return m_btCollisionShape; }

	btCollisionObject*	GetBTCollider()			{ return m_btCollider; }
	btCollisionShape*	GetBTCollisionShape()	{ return m_btCollisionShape; }

	void SetBTCollisionObject(btCollisionObject* const _collisionObject);

	const math::Transform& GetTransform() const override { return m_transform; }
	math::Transform& GetTransform()				override { return m_transform; }

	PADObject* const			GetOwner() const		override	{ return m_owner; }
	const COMPONENT_TYPE		GetType() const			override	{ return m_type; }

	void	SetOwner(PADObject* const _owner)			override { m_owner = _owner; }

protected:
	btCollisionObject*	m_btCollider;
	btCollisionShape*	m_btCollisionShape;
};

} // namespace ecs
} // namespace sys
} // namespace pad