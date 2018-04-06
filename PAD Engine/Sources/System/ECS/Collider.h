#pragma once

#include <System/ECS/IComponent.h>
#include <Bullet/btBulletDynamicsCommon.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class Collider : public IComponent
{
public:
	Collider();
	~Collider();

public:
	void Init(PADObject* const _owner)	override;
	void Start()						override;
	void Update()						override;
	void FixedUpdate()					override;
	void LateUpdate()					override;


public:
	virtual void				SetOwner(PADObject* const _owner) { m_owner = _owner; }
	virtual PADObject* const	GetOwner() const { return m_owner; }

	virtual const COMPONENT_TYPE GetType() const override { return m_type; }

	btCollisionObject* const GetBTCollider() const { return m_btCollider; }

private:
	btCollisionObject* m_btCollider;
};

} // namespace ecs
} // namespace sys
} // namespace pad