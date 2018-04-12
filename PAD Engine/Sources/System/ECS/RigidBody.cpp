#include <System/ECS/RigidBody.h>
#include <Core/Engine.h>

namespace pad	{
namespace sys	{
namespace ecs	{

RigidBody::RigidBody() :
	m_collider(nullptr),
	m_btMotionState(nullptr),
	m_btRigidBody(nullptr)
{
	m_type = COMPONENT_TYPE::RIGIDBODY;
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
	m_transform = m_owner->GetTransform();
	btTransform t(btMatrix3x3(), btVector3(	m_owner->GetTransform().Position().x,
											m_owner->GetTransform().Position().y,
											m_owner->GetTransform().Position().z));

	m_btMotionState = new btDefaultMotionState();

	for (auto comp : m_owner->GetComponents())
	{
		if (comp->GetType() == COMPONENT_TYPE::COLLIDER)
		{
			m_collider = static_cast<ACollider*>(comp);
			break;
		}
	}

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


	m_btRigidBody->getWorldTransform().setOrigin(btVector3(	m_transform.Position().x,
															m_transform.Position().y,
															m_transform.Position().z));

	//m_btRigidBody->getWorldTransform().setRotation(btQuaternion(	m_transform.Rotation().y,
	//																m_transform.Rotation().x,
	//																m_transform.Rotation().z));

	core::Engine::GetPhysicContext()->AddRigidBody(this);
}

void RigidBody::Start()
{

}

void RigidBody::Update()
{
	m_btRigidBody->getWorldTransform().setOrigin(btVector3(	m_owner->GetTransform().Position().x,
															m_owner->GetTransform().Position().y,
															m_owner->GetTransform().Position().z));

	//m_btRigidBody->getWorldTransform().setRotation(btQuaternion(	m_owner->GetTransform().Rotation().y,
	//																m_owner->GetTransform().Rotation().x,
	//																m_owner->GetTransform().Rotation().z));
}

void RigidBody::FixedUpdate()
{
	m_owner->GetTransform().SetPosition(m_btRigidBody->getWorldTransform().getOrigin());
	m_owner->GetTransform().SetQuatRotation(math::Quat(	m_btRigidBody->getWorldTransform().getRotation().x(),
														m_btRigidBody->getWorldTransform().getRotation().y(),
														m_btRigidBody->getWorldTransform().getRotation().z(),
														m_btRigidBody->getWorldTransform().getRotation().w()));
}

void RigidBody::LateUpdate()
{
	m_btRigidBody->getWorldTransform().setOrigin(btVector3(m_owner->GetTransform().Position().x,
		m_owner->GetTransform().Position().y,
		m_owner->GetTransform().Position().z));

	//m_btRigidBody->getWorldTransform().setRotation(btQuaternion(	m_owner->GetTransform().Rotation().y,
	//																m_owner->GetTransform().Rotation().x,
	//																m_owner->GetTransform().Rotation().z));
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

inline void RigidBody::SetCollider(ACollider* const _collider)
{
	m_collider = _collider;
}

} // namespace ecs
} // namespace sys
} // namespace pad