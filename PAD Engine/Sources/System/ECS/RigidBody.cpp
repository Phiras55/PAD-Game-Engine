#include <System/ECS/RigidBody.h>

namespace pad	{
namespace sys	{
namespace ecs	{

RigidBody::RigidBody()
{
}

RigidBody::~RigidBody()
{
}

void RigidBody::Init()
{
}

void RigidBody::Start()
{
	// rigidBody.transform = parent.transform
}

void RigidBody::Update()
{
	// rigidBody.transform = parent.transform
}

void RigidBody::FixedUpdate()
{
	// parent.transform = rigidBody.transform
}

void RigidBody::LateUpdate()
{

}

void RigidBody::SetMass(const float _mass)
{
	// TO DO
}

} // namespace ecs
} // namespace sys
} // namespace pad