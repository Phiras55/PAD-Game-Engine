#pragma once

#include <System/ECS/ACollider.h>
#include <Utilities/Export.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API BoxCollider final : public ACollider
{
public:
	BoxCollider(const math::Vec3f _halfBox = math::Vec3f(1.f, 1.f, 1.f));
	virtual ~BoxCollider();

private:	
	btBoxShape* m_boxShape;

public:
	void Init()			override;
	void Start()		override;
	void Update()		override;
	void FixedUpdate()	override;
	void LateUpdate()	override;

	PADObject* const			GetOwner() const		override	{ return m_owner; }
	const COMPONENT_TYPE		GetType() const			override	{ return m_type; }

	void	SetOwner(PADObject* const _owner)	override { m_owner = _owner; }
};

} // namespace ecs
} // namespace sys
} // namespace pad