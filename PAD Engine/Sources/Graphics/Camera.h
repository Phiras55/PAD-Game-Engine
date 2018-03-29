#pragma once
#include <Math/Matrix4x4.h>
#include <System/ECS/IComponent.h>
#include <Math/Transform.h>

namespace pad	{
namespace gfx	{

class Camera : public sys::ecs::IComponent
{
protected:
	Camera()	= delete;
	Camera(math::Transform* const _transform);
	~Camera()	= default;

protected:
	math::Mat4 m_projectionMatrix;
	math::Mat4 m_viewMatrix;

public:
	inline const math::Mat4& GetProjection()	{ return m_projectionMatrix; }
	inline const math::Mat4& GetView()			{ return m_viewMatrix; }

protected:
	virtual void Init()			override;
	virtual void Start()		override;
	virtual void Update()		override;
	virtual void FixedUpdate()	override;
	virtual void LateUpdate()	override;
};

} // namespace gfx
} // namespace pad