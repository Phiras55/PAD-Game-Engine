#include <System/ECS/BoxCollider.h>
#include <Core/Engine.h>

namespace pad	{
namespace sys	{
namespace ecs	{

BoxCollider::BoxCollider(const math::Vec3f _halfBox)
{
	m_type			= COLLIDER;
	m_btCollider	= new btCollisionObject();
	m_boxShape		= new btBoxShape(btVector3(_halfBox.x, _halfBox.y, _halfBox.z));

	m_btCollider->setCollisionShape(m_boxShape);
}

BoxCollider::~BoxCollider()
{

}

void BoxCollider::Init()
{
	ACollider::Init();
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

} // namespace ecs
} // namespace sys
} // namespace pad