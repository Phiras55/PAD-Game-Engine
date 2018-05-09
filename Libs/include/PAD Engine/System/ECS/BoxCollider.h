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
	virtual ~BoxCollider();

	const alias::ComponentID GetType() const override
	{
		return static_cast<alias::ComponentID>(
			util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
	}

private:	
	btBoxShape* m_boxShape;

public:
	void Init()								override;
	void Start()							override;
	void Update()							override;
	void FixedUpdate()						override;
	void LateUpdate()						override;

	json Serialize()						override;
	void Deserialize(const json& j)			override;
};

} // namespace ecs
} // namespace sys
} // namespace pad