#pragma once
#include <System/ECS/RigidBody.h>

namespace pad	{
namespace sys	{
namespace phx	{

class IPhysicContext
{
public:
	virtual void Init()		= 0;
	virtual void Update()	= 0;
	virtual void Clean()	= 0;

	virtual void AddRigidBody(ecs::RigidBody* const _rigidBody)			= 0;
	virtual void AddCollider(ecs::ACollider* const _collider)			= 0;

	virtual void RemoveCollider(ecs::ACollider* const _collider)		= 0;
	virtual void RemoveRigidBody(ecs::RigidBody* const _rigidBody)		= 0;
};

} // namespace phx
} // namespace sys
} // namespace pad