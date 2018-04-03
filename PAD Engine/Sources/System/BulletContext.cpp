#include <System/BulletContext.h>
#include <Core/EngineClock.h>

namespace pad	{
namespace sys	{

BulletContext::BulletContext()
{	
	// TO DO : Physic Settings
	//collisionConfiguration	= new btDefaultCollisionConfiguration();
	//dispatcher				= new btCollisionDispatcher(collisionConfiguration);
	//broadphaseInterface		= new btDbvtBroadphase();
	//solver					= new btSequentialImpulseConstraintSolver();
	//dynamicsWorld			= new btDiscreteDynamicsWorld(	dispatcher,
															//broadphaseInterface,
															//solver,
															//collisionConfiguration);

	//dynamicsWorld->setGravity(btVector3(0, -10, 0));
}

BulletContext::~BulletContext()
{
}

void BulletContext::Init()
{
}

void BulletContext::Update()
{
	//dynamicsWorld->stepSimulation(core::EngineClock::DeltaTime());
}

void BulletContext::Clean()
{
	//delete collisionConfiguration;
	//delete dispatcher;
	//delete broadphaseInterface;
	//delete solver;
	//delete dynamicsWorld;
}

void BulletContext::AddRigidBody(ecs::RigidBody* const _rigidBody)
{
	//dynamicsWorld->addRigidBody(_rigidBody->GetBTRigidBody());
}

void BulletContext::AddCollider(ecs::Collider* const _collider)
{
	//dynamicsWorld->addCollisionObject(_collider->GetBTCollider());
}

} // namespace sys
} // namespace pad