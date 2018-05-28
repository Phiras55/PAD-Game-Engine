#pragma once
#include <System/ECS/ACollider.h>
#include <Utilities/Export.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API BoxCollider final : public ACollider
{
public:
	BoxCollider(const math::Vec3f _dimention = math::Vec3f(1.f, 1.f, 1.f));
	BoxCollider(const BoxCollider& _other);
	virtual ~BoxCollider();

	const alias::ComponentID GetType() const override
	{
		return m_id;
	}

	inline const std::string& GetName() override { return m_name; }

private:	
	btBoxShape*					m_boxShape;
	static alias::ComponentID	m_id;
	const std::string			m_name = "BoxCollider";

public:
	void Init()								override;
	void Start()							override;
	void Update()							override;
	void FixedUpdate()						override;
	void LateUpdate()						override;

	json Serialize()						override;
	void Deserialize(const json& j)			override;

public:
	void operator=(const BoxCollider& _other);
};

} // namespace ecs
} // namespace sys
} // namespace pad