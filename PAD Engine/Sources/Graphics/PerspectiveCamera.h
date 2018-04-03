#pragma once
#include <Math/Matrix4x4.h>
#include <Graphics/Camera.h>

namespace pad	{
namespace gfx	{

class ENGINE_API PerspectiveCamera final : public Camera
{
public:
	PerspectiveCamera()		= delete;
	PerspectiveCamera(math::Transform* const _transform);
	~PerspectiveCamera();

public:
	const math::Mat4& Perspective(float _fov, float _aspectRatio, float _near, float _far);
	const math::Mat4& LookAt(const math::Vec3f& _eyePos, const math::Vec3f& _target, const math::Vec3f& _up);
};

} // namespace gfx
} // namespace pad