#pragma once

#include <btBulletDynamicsCommon.h>
#include <System/IPhysicContext.h>

namespace pad	{
namespace sys	{

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

} // namespace sys
} // namespace pad