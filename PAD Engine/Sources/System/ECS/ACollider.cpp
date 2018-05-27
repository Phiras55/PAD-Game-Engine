#include <EnginePCH.h>
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

}

void ACollider::Init()
{

}

void ACollider::SetBTCollisionObject(btCollisionObject* const _collisionObject)
{
	core::Engine::GetPhysicContext()->RemoveCollider(this);
	m_btCollider = _collisionObject;
}

} // namespace ecs
} // namespace sys
} // namespace pad