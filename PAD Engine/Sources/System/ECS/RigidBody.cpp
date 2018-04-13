#include <System/ECS/RigidBody.h>

namespace pad	{
namespace sys	{
namespace ecs	{

RigidBody::RigidBody()
{
	m_type = COMPONENT_TYPE::RIGIDBODY;
}

RigidBody::~RigidBody()
{

}

void RigidBody::Init(PADObject* const _owner)
{
	m_owner = _owner;
}

void RigidBody::Start()
{
	btCollisionShape* collider;

	for (auto comp : m_owner->GetComponents())
	{
		if (comp->GetType() == COMPONENT_TYPE::COLLIDER)
		{

		}
	}
	//btTransform btTrans;
	//btTrans.setOrigin(btVector3(m_owner->GetTransform().Position().x,
	//							m_owner->GetTransform().Position().y,
	//							m_owner->GetTransform().Position().z));
	//
	//m_btMotionState = new btDefaultMotionState(btTrans);
}

void RigidBody::Update()
{
	// rigidBody.transform = parent.transform
}

void RigidBody::FixedUpdate()
{

}

void RigidBody::LateUpdate()
{
	// parent.transform = rigidBody.transform
}

void RigidBody::SetMass(const float _mass)
{
	// TO DO
}

} // namespace ecs
} // namespace sys
} // namespace pad