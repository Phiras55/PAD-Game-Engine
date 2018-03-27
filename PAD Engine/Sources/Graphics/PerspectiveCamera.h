#pragma once
#include <Math/Matrix4x4.h>
#include <Graphics/Camera.h>
namespace pad	{

	class PerspectiveCamera final : public Camera
	{
	public:
		PerspectiveCamera();
		~PerspectiveCamera();

	public:
		const math::Mat4& Perspective	(float _fov, float _aspectRatio, float _near, float _far);
		const math::Mat4& LookAt		(math::Vec3f& eye, math::Vec3f& center, math::Vec3f& up);


};

} // namespace pad