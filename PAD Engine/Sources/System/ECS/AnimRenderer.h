#pragma once

#include <Utilities/Export.h>
#include <System/ECS/MeshRenderer.h>
#include <Core/Timer.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API AnimRenderer : public MeshRenderer
{
public:
	AnimRenderer();
	AnimRenderer(const AnimRenderer& _other);
	AnimRenderer(const std::string& _meshName, const std::string& _materialName, const std::string& _skeletonName);
	~AnimRenderer();

private:
	std::string m_skeletonName;
	std::string m_currentAnim;
	int			m_currentKey;
	float		m_keyFrameDuration;
	core::Timer	m_animTimer;

private:
	static alias::ComponentID	m_AR_id;

public:
	void Init()								override;
	void Start()							override;
	void Update()							override;
	void FixedUpdate()						override;
	void LateUpdate()						override;

	json Serialize()						override;
	void Deserialize(const json& j)			override;

public:
	inline const alias::ComponentID GetType() const override { return m_AR_id; }

public:
	void operator=(const AnimRenderer& _other);
};

} // namespace ecs
} // namespace sys
} // namespace pad