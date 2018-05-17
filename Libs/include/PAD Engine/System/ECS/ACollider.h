#pragma once
#include <System/ECS/AComponent.h>
#include <Bullet/btBulletDynamicsCommon.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API ACollider : public AComponent
{
public:
	ACollider();
	virtual ~ACollider();

	void Init()	override;

	virtual const alias::ComponentID GetType() const override
	{
		return static_cast<alias::ComponentID>(
			util::GetTypeID<std::remove_reference_t<decltype(*this)>>());
	}

public:
	btCollisionObject* const	GetBTCollider() const			{ return m_btCollider; }
	btCollisionShape* const		GetBTCollisionShape() const		{ return m_btCollisionShape; }

	btCollisionObject*	GetBTCollider()			{ return m_btCollider; }
	btCollisionShape*	GetBTCollisionShape()	{ return m_btCollisionShape; }

	void SetBTCollisionObject(btCollisionObject* const _collisionObject);

protected:
	btCollisionObject*	m_btCollider;
	btCollisionShape*	m_btCollisionShape;
};

} // namespace ecs
} // namespace sys
} // namespace pad