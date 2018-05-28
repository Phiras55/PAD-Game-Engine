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

public:
	const math::Mat4& Perspective(float _fov, float _aspectRatio, float _near, float _far) override;
	const math::Mat4& LookAt(const math::Vec3f& _eyePos, const math::Vec3f& _target, const math::Vec3f& _up) override;

	virtual void				SetOwner(PADObject* const _owner)	{ m_owner = _owner; }
	virtual PADObject* const	GetOwner() const					{ return m_owner; }

	json Serialize()				override;
	void Deserialize(const json& j)	override;

	inline float GetFov()			{ return m_fov; }
	inline float GetAspectRatio()	{ return m_aspectRatio; }
	inline float GetNear()			{ return m_near; }
	inline float GetFar()			{ return m_far; }


	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

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
	float						m_fov;
	float						m_aspectRatio;
	float						m_near;
	float						m_far;
	float						m_speed;
};

} // namespace ecs
} // namespace sys
} // namespace pad