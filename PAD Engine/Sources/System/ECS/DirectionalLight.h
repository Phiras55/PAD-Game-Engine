#pragma once
#include <System/ECS/ALight.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class DirectionalLight : public ALight
{
public:
	DirectionalLight();
	~DirectionalLight();

	DirectionalLight(const DirectionalLight& _other);
	DirectionalLight(DirectionalLight&&) = default;

private:
	static alias::ComponentID	m_id;
	const std::string			m_name = "DirectionalLight";

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

	inline const std::string& GetName() override { return m_name; }

public:
	void operator=(const DirectionalLight& _other);
};

} // namespace ecs
} // namespace sys
} // namespace pad