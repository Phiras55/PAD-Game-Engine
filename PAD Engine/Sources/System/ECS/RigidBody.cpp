#include <EnginePCH.h>
#include <System/ECS/RigidBody.h>
#include <Core/Engine.h>

namespace pad	{
namespace sys	{
namespace ecs	{

alias::ComponentID RigidBody::m_id = INVALID_COMPONENT_ID;

RigidBody::RigidBody() :
	m_collider(nullptr),
	m_btMotionState(nullptr),
	m_btRigidBody(nullptr)
{
	if (m_id != INVALID_COMPONENT_ID)
		m_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
}

RigidBody::RigidBody(const RigidBody& _other)	:
	RigidBody()
{

}

RigidBody::~RigidBody()
{
	if (m_btMotionState)
		delete m_btMotionState;
	if (m_btRigidBody)
		delete m_btRigidBody;
}

void RigidBody::Init()
{
	m_collider = m_owner->GetCollider();
	m_btMotionState = new btDefaultMotionState();

	btVector3 inertia(0, 0, 0);
	if (m_collider)
	{
		btCollisionShape* collider = m_collider->GetBTCollider()->getCollisionShape();
		collider->calculateLocalInertia(m_mass, inertia);
		m_btRigidBody = new btRigidBody(m_mass, m_btMotionState, collider, inertia);
		m_collider->SetBTCollisionObject(m_btRigidBody);
	}
	else
		m_btRigidBody = new btRigidBody(m_mass, m_btMotionState, nullptr, inertia);


	m_btRigidBody->getWorldTransform().setOrigin(btVector3(	m_owner->GetTransform().Position().x,
															m_owner->GetTransform().Position().y,
															m_owner->GetTransform().Position().z));

	m_btRigidBody->getWorldTransform().setRotation(btQuaternion(m_owner->GetTransform().QuatRotation().x,
																m_owner->GetTransform().QuatRotation().y,
																m_owner->GetTransform().QuatRotation().z,
																m_owner->GetTransform().QuatRotation().w));

	core::Engine::GetPhysicContext()->AddRigidBody(this);
}

void RigidBody::Start()
{

}

void RigidBody::Update()
{
	if (!m_btRigidBody)
		return;

	m_btRigidBody->getWorldTransform().setOrigin(btVector3(	m_owner->GetTransform().Position().x,
															m_owner->GetTransform().Position().y,
															m_owner->GetTransform().Position().z));

	m_btRigidBody->getWorldTransform().setRotation(btQuaternion(m_owner->GetTransform().QuatRotation().x,
																m_owner->GetTransform().QuatRotation().y,
																m_owner->GetTransform().QuatRotation().z,
																m_owner->GetTransform().QuatRotation().w));
}

void RigidBody::FixedUpdate()
{
	if (!m_btRigidBody)
		return;

	m_owner->GetTransform().SetPosition(m_btRigidBody->getWorldTransform().getOrigin());

	m_owner->GetTransform().SetQuatRotation(math::Quat(	m_btRigidBody->getWorldTransform().getRotation().x(),
														m_btRigidBody->getWorldTransform().getRotation().y(),
														m_btRigidBody->getWorldTransform().getRotation().z(),
														m_btRigidBody->getWorldTransform().getRotation().w()));
}

void RigidBody::LateUpdate()
{
	//m_owner->GetTransform().SetPosition(m_btRigidBody->getWorldTransform().getOrigin());

	//m_owner->GetTransform().SetQuatRotation(math::Quat(	m_btRigidBody->getWorldTransform().getRotation().x(),
	//													m_btRigidBody->getWorldTransform().getRotation().y(),
	//													m_btRigidBody->getWorldTransform().getRotation().z(),
	//													m_btRigidBody->getWorldTransform().getRotation().w()));
}

void RigidBody::SetMass(const float _mass)
{
	m_mass = _mass;
	btVector3 inertia(0, 0, 0);

	if (m_collider)
		m_collider->GetBTCollider()->getCollisionShape()->calculateLocalInertia(_mass, inertia);

	if (m_btRigidBody)
		m_btRigidBody->setMassProps(_mass, inertia);
}

json RigidBody::Serialize()
{
	json j;

	return j;
}

void RigidBody::Deserialize(const json& j)
{

}

void RigidBody::operator=(const RigidBody& _other)
{

}

} // namespace ecs
} // namespace sys
} // namespace pad

