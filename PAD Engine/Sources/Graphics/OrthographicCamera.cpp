#include <Graphics/OrthographicCamera.h>
#include <Math/Vector3.h>

namespace pad	{
namespace gfx	{

OrthographicCamera::OrthographicCamera()
{
}
OrthographicCamera::~OrthographicCamera()
{
}
const math::Mat4& OrthographicCamera::Perspective(float v, float r, float n, float f) //v = FOV, r = aspectRatio, n = near, f = far
{
	_projectionMatrix = math::Mat4(
	  1/r,				0,				0,				0,
		0,			  1/v,				0,				0,
		0,				0,		 -2/(f-n), -((f+n)/(f-n)),
		0,				0,				0,				1);

	return _projectionMatrix;
}

const math::Mat4& OrthographicCamera::LookAt(const math::Vec3f& eye, const math::Vec3f& at, const math::Vec3f& up)
{


	return math::Mat4();
}

} // namespace gfx
} // namespace pad
