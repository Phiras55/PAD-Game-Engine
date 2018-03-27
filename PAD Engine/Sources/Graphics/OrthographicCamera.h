#pragma once
#include <Math/Matrix4x4.h>
#include <Graphics/Camera.h>
namespace pad	{
namespace gfx	{

class OrthographicCamera final : public Camera
{
public:
	OrthographicCamera();
	~OrthographicCamera();

public:
	const math::Mat4& Perspective	(float _fov, float _aspectRatio, float _near, float _far);
	const math::Mat4& LookAt		(const math::Vec3f& eye, const math::Vec3f& center, const math::Vec3f& up);
};

} // namespace gfx
} // namespace pad