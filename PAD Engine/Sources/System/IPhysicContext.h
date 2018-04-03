#pragma once

#include <System/ECS/RigidBody.h>

namespace pad	{
namespace sys	{

class IPhysicContext
{
public:
	virtual void Init()		= 0;
	virtual void Update()	= 0;
	virtual void Clean()	= 0;

	virtual void AddRigidBody(ecs::RigidBody* const _rigidBody) = 0;
	virtual void AddCollider(ecs::Collider* const _collider)	= 0;
};

} // namespace sys
} // namespace pad