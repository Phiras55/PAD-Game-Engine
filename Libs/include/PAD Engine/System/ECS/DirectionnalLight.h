#pragma once
#include <System/ECS/ALight.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class DirectionnalLight : public ALight
{
public:
	DirectionnalLight();
	~DirectionnalLight();

	DirectionnalLight(const DirectionnalLight& _other);
	DirectionnalLight(DirectionnalLight&&) = default;

private:
	static alias::ComponentID m_id;

public:
	void Init()								override;
	void Start()							override;
	void Update()							override;
	void FixedUpdate()						override;
	void LateUpdate()						override;

	json Serialize()						override;
	void Deserialize(const json& j)			override;

	const alias::ComponentID GetType() const override
	{
		return m_id;
	}

public:
	void operator=(const DirectionnalLight& _other);
};

} // namespace ecs
} // namespace sys
} // namespace pad