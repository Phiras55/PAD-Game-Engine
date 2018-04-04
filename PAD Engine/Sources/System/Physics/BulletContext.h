#pragma once
#include <Bullet/btBulletDynamicsCommon.h>
#include <System/Physics/IPhysicContext.h>

namespace pad	{
namespace sys	{
namespace phx	{

class BulletContext final : public IPhysicContext
{
public:
	BulletContext();
	~BulletContext();

public:
	void Init()		override;
	void Update()	override;
	void Clean()	override;

	void AddRigidBody(ecs::RigidBody* const _rigidBody) override;
	void AddCollider(ecs::Collider* const _collider)	override;

private:
	btDefaultCollisionConfiguration*		collisionConfiguration;
	btCollisionDispatcher*					dispatcher;
	btBroadphaseInterface*					broadphaseInterface;
	btSequentialImpulseConstraintSolver*	solver;
	btDiscreteDynamicsWorld*				dynamicsWorld;
};

} // namespace phx
} // namespace sys
} // namespace pad