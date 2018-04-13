#include <System/ECS/ACollider.h>
#include <Core/Engine.h>

namespace pad	{
namespace sys	{
namespace ecs	{

ACollider::ACollider() :
	m_btCollider(nullptr),
	m_btCollisionShape(nullptr)
{

}

ACollider::~ACollider()
{
	if (m_btCollider)
		delete m_btCollider;

	if (m_btCollisionShape)
		delete m_btCollisionShape;
}

void ACollider::Init()
{
//	m_transform = m_owner->GetTransform();

	RigidBody* rb = nullptr;
	for (auto comp : m_owner->GetComponents())
	{
		if (comp->GetType() == COMPONENT_TYPE::RIGIDBODY)
		{
			rb = static_cast<RigidBody*>(comp);
			if (!rb->GetCollider())
			{
				rb->SetCollider(this);
				return;
			}
		}
	}

	if (!rb)
		core::Engine::GetPhysicContext()->AddCollider(this);
}

void ACollider::SetBTCollisionObject(btCollisionObject* const _collisionObject)
{
	core::Engine::GetPhysicContext()->RemoveCollider(this);
	m_btCollider = _collisionObject;
}

} // namespace ecs
} // namespace sys
} // namespace pad