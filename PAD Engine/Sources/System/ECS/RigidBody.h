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
	RigidBody(const RigidBody& _other);
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

	inline void SetCollider(ACollider* const _collider)				{ m_collider = _collider; }

	const alias::ComponentID GetType() const override
	{
		return m_id;
	}

	inline const std::string& GetName() override { return m_name; }
	
private:
	btRigidBody*				m_btRigidBody;
	btMotionState*				m_btMotionState;
	ACollider*					m_collider;
	float						m_mass;
	static alias::ComponentID	m_id;
	const std::string			m_name = "RigidBody";

public:
	void operator=(const RigidBody& _other);
};

} // namespace ecs
} // namespace sys
} // namespace pad