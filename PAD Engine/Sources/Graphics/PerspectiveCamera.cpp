#include <Graphics/PerspectiveCamera.h>
#include <Math/Transform.h>
#include <Math/Vector3.h>

namespace pad	{
namespace gfx	{

PerspectiveCamera::PerspectiveCamera()
{
}

PerspectiveCamera::~PerspectiveCamera()
{
}

const math::Mat4& PerspectiveCamera::Perspective(float v, float r, float n, float f) //v = FOV, r = aspectRatio, n = near, f = far
{
	float fovTan = tan(math::DegreeToRad(v) / 2.f);

	_projectionMatrix[0][0] = 1.f / (fovTan * r);
	_projectionMatrix[1][1] = 1.f / fovTan;
	_projectionMatrix[2][2] = -(f + n) / (f - n);
	_projectionMatrix[2][3] = (-2 * f * n) / (f - n);
	_projectionMatrix[3][2] = -1.f;
	_projectionMatrix[3][3] = 0.f;

	return _projectionMatrix;
}

const math::Mat4& PerspectiveCamera::LookAt(const math::Vec3f& eye, const math::Vec3f& at, const math::Vec3f& up)
{
	math::Vec3f h(eye - at); // zc = h
	h.Normalize();
	
	math::Vec3f f = math::CrossProduct(up, h).Normalized(); // f = xc
	
	math::Vec3f g = math::CrossProduct(h, f); // g = yc

	float fe = math::DotProduct(f, -eye); // ex = fe
	float ge = math::DotProduct(g, -eye); // ey = ge
	float he = math::DotProduct(h, -eye); // ez = he

	//float fe = -math::DotProduct(f, eye);
	//float ge = -math::DotProduct(g, eye);
	//float he = -math::DotProduct(h, eye);

	//_viewMatrix = math::Mat4(	f.x, f.y, f.z, fe,
								//g.x, g.y, g.z, ge,
								//h.x, h.y, h.z, he,
								//0.f, 0.f, 0.f, 1);

	_viewMatrix[0][0] = f.x;
	_viewMatrix[0][1] = f.y;
	_viewMatrix[0][2] = f.z;
	_viewMatrix[0][3] = fe;

	_viewMatrix[1][0] = g.x;
	_viewMatrix[1][1] = g.y;
	_viewMatrix[1][2] = g.z;
	_viewMatrix[1][3] = ge;

	_viewMatrix[2][0] = h.x;
	_viewMatrix[2][1] = h.y;
	_viewMatrix[2][2] = h.z;
	_viewMatrix[2][3] = he;

	return _viewMatrix;
}

} // namespace gfx
} // namespace pad
