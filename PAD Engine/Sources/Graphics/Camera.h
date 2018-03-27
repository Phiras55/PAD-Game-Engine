#pragma once
#include <Math/Matrix4x4.h>
namespace pad	{

	class Camera
	{
	public:
		Camera();
		~Camera();

	private:
		math::Mat4 _projectionMatrix;
		math::Mat4 _viewMatrix;

	public:
		const math::Mat4& Perspective	(float _fov, float _aspectRatio, float _near, float _far);
		const math::Mat4& LookAt		(math::Vec3f& eye, math::Vec3f& center, math::Vec3f& up);

	public:
		inline const math::Mat4& GetProjection()	{ return _projectionMatrix; }
		inline const math::Mat4& GetView()			{ return _viewMatrix; }

};

} // namespace pad