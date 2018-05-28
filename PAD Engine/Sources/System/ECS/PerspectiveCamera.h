#pragma once
#include <Math/Transform.h>
#include <System/ECS/Camera.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API PerspectiveCamera final : public Camera
{
public:
	PerspectiveCamera();
	~PerspectiveCamera();

public:
	void Init()						override;
	void Start()					override;
	void Update()					override;
	void FixedUpdate()				override;
	void LateUpdate()				override;

	json Serialize()				override;
	void Deserialize(const json& j)	override;

public:
	const math::Mat4& Perspective(float _fov, float _aspectRatio, float _near, float _far) override;
	const math::Mat4& LookAt(const math::Vec3f& _eyePos, const math::Vec3f& _target, const math::Vec3f& _up) override;
	void MoveForward(const float32 _speed);
	void MoveBackward(const float32 _speed);
	void FirstPersonMouseInput(
		const math::Vec2i& _mousePos,
		const math::Vec2i& _windowSize);

	const alias::ComponentID GetType() const override
	{
		return m_id;
	}

	inline const std::string& GetName() override { return m_name; }

public:
	void operator=(const PerspectiveCamera& _other)
	{
		_projectionMatrix = _other._projectionMatrix;
		_viewMatrix = _other._viewMatrix;
	}

private:
	static alias::ComponentID	m_id;
	const std::string			m_name = "PerspectiveCamera";
};

} // namespace ecs
} // namespace sys
} // namespace pad