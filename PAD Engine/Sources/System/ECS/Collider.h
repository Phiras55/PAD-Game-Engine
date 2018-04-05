#pragma once

#include <System/ECS/IComponent.h>
#include <Bullet/btBulletDynamicsCommon.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class Collider : public IComponent
{
public:
	Collider();
	~Collider();

public:
	btCollisionObject* const GetBTCollider() const { return m_btCollider; }

private:
	btCollisionObject* m_btCollider;
};

} // namespace ecs
} // namespace sys
} // namespace pad