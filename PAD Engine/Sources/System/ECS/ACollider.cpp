#include "ACollider.h"
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

} // namespace ecs
} // namespace sys
} // namespace pad