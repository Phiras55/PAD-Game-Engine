#pragma once
#include <Math/Transform.h>
#include <Graphics/Camera.h>

namespace pad	{
namespace gfx	{

class ENGINE_API PerspectiveCamera final : public Camera
{
public:
	PerspectiveCamera();
	PerspectiveCamera(math::Transform* const _transform);
	~PerspectiveCamera();

public:
	const math::Mat4& Perspective(float _fov, float _aspectRatio, float _near, float _far) override;
	const math::Mat4& LookAt(const math::Vec3f& _eyePos, const math::Vec3f& _target, const math::Vec3f& _up) override;
};

} // namespace gfx
} // namespace pad