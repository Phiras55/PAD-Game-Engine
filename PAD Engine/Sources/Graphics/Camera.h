#pragma once
#include <Math/Matrix4x4.h>
#include <Utilities/Export.h>

namespace pad	{
namespace gfx	{

class ENGINE_API Camera
{
protected:
	math::Mat4 _projectionMatrix;
	math::Mat4 _viewMatrix;

public:
	virtual const math::Mat4& Perspective(float _fov, float _aspectRatio, float _near, float _far)				= 0;
	virtual const math::Mat4& LookAt(const math::Vec3f& eye, const math::Vec3f& center, const math::Vec3f& up)	= 0;

public:
	inline const math::Mat4& GetProjection()	{ return _projectionMatrix; }
	inline const math::Mat4& GetView()			{ return _viewMatrix; }
};

} // namespace gfx
} // namespace pad