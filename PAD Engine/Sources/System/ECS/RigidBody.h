#pragma once

#include <System/ECS/AComponent.h>
#include <System/ECS/ACollider.h>
#include <Utilities/Export.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API RigidBody final : public AComponent
{
public:
	RigidBody();
	~RigidBody();

public:
	void Init()			override;
	void Start()		override;
	void Update()		override;
	void FixedUpdate()	override;
	void LateUpdate()	override;

	json Serialize()						override;
	void Deserialize(const json& j)			override;

public:
	inline void SetMass(const float _mass);

	inline btRigidBody* const	GetBTRigidBody() const				{ return m_btRigidBody; }
	inline ACollider*	const	GetCollider() const					{ return m_collider; }

	inline void SetCollider(ACollider* const _collider);

	const alias::ComponentID GetType() const override
	{
		return static_cast<alias::ComponentID>(
			util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
	}
	
private:
	btRigidBody*	m_btRigidBody;
	btMotionState*	m_btMotionState;
	ACollider*		m_collider;
	float			m_mass;
};

} // namespace ecs
} // namespace sys
} // namespace pad