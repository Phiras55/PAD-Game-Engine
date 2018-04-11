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
	void AddCollider(ecs::ACollider* const _collider)	override;

	void RemoveCollider(ecs::ACollider* const _collider) override;
	void RemoveRigidBody(ecs::RigidBody* const _rigidBody) override;

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