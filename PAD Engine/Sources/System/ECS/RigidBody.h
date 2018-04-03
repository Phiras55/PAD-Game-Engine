#pragma once

#include <System/ECS/IComponent.h>
#include <System/ECS/Collider.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class RigidBody final : public IComponent
{
public:
	RigidBody();
	~RigidBody();

public:
	virtual void Init();
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void LateUpdate();

public:
	inline void SetMass(const float _mass);

//	inline btRigidBody* const GetBTRigidBody() const { return m_btRigidBody; }

private:
	//btRigidBody*	m_btRigidBody;
	Collider*		m_collider;
};

} // namespace ecs
} // namespace sys
} // namespace pad