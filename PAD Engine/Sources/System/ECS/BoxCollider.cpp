#include <EnginePCH.h>
#include <System/ECS/BoxCollider.h>
#include <Core/Engine.h>

namespace pad	{
namespace sys	{
namespace ecs	{

BoxCollider::BoxCollider(const math::Vec3f _dimention)
{
	m_btCollider		= new btCollisionObject();
	m_boxShape			= new btBoxShape(btVector3(_dimention.x / 2.f, _dimention.y / 2.f, _dimention.z / 2.f));
	m_btCollisionShape	= m_boxShape;

	m_btCollider->setCollisionShape(m_boxShape);
}

BoxCollider::~BoxCollider()
{

}

void BoxCollider::Init()
{
	ACollider::Init();

	m_btCollider->getWorldTransform().setOrigin(
		btVector3(	
			m_owner->GetTransform().Position().x,
			m_owner->GetTransform().Position().y,
			m_owner->GetTransform().Position().z));
}

void BoxCollider::Start()
{

}

void BoxCollider::Update()
{

}

void BoxCollider::FixedUpdate()
{

}

void BoxCollider::LateUpdate()
{

}

json BoxCollider::Serialize()
{
	json j;

	return j;
}

void BoxCollider::Deserialize(const json& j)
{

}

} // namespace ecs
} // namespace sys
} // namespace pad