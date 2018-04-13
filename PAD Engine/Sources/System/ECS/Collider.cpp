#include <System/ECS/Collider.h>

namespace pad	{
namespace sys	{
namespace ecs	{
	
Collider::Collider()
{
	m_type = COMPONENT_TYPE::COLLIDER;
}

Collider::~Collider()
{
}

void Collider::Init(PADObject * const _owner)
{
}

void Collider::Start()
{
}

void Collider::Update()
{
}

void Collider::FixedUpdate()
{
}

void Collider::LateUpdate()
{
}

} // namespace ecs
} // namespace sys
} // namespace pad