#include <EnginePCH.h>
#include <System/ECS/BoxCollider.h>
#include <Core/Engine.h>

namespace pad	{
namespace sys	{
namespace ecs	{

alias::ComponentID BoxCollider::m_id = INVALID_COMPONENT_ID;

BoxCollider::BoxCollider(const math::Vec3f _dimention)
{
	if (m_id != INVALID_COMPONENT_ID)
		m_id = static_cast<alias::ComponentID>(util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());

	m_btCollider		= new btCollisionObject();
	m_boxShape			= new btBoxShape(btVector3(_dimention.x * 0.5f, _dimention.y * 0.5f, _dimention.z * 0.5f));
	m_btCollisionShape	= m_boxShape;

	m_btCollider->setCollisionShape(m_boxShape);
}

BoxCollider::BoxCollider(const BoxCollider& _other)
{
	m_btCollider		= new btCollisionObject(*_other.m_btCollider);
	m_boxShape			= new btBoxShape(*_other.m_boxShape);
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

	math::Vec3f v(m_boxShape->getHalfExtentsWithMargin());
	v *= 2;
	AddDataToJson(j, "dimensions", v.Serialize());

	return j;
}

void BoxCollider::Deserialize(const json& j)
{
	math::Vec3f v;
	v.Deserialize(JsonToData<json>(j, "dimensions"));

	m_boxShape->setLocalScaling(btVector3(v.x, v.y, v.z));
}

void BoxCollider::operator=(const BoxCollider& _other)
{
	m_btCollider		= _other.m_btCollider;
	m_boxShape			= _other.m_boxShape;
	m_btCollisionShape	= m_boxShape;

	m_btCollider->setCollisionShape(m_boxShape);
}

} // namespace ecs
} // namespace sys
} // namespace pad