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

	void SetBTCollisionObject(btCollisionObject* const _collisionObject);

protected:
	btCollisionObject*	m_btCollider;
	btCollisionShape*	m_btCollisionShape;
};

} // namespace ecs
} // namespace sys
} // namespace pad