#include <Graphics/PerspectiveCamera.h>
#include <Math/Transform.h>
#include <Math/Vector3.h>

namespace pad	{
namespace gfx	{

PerspectiveCamera::PerspectiveCamera(math::Transform* const _transform)
{
	m_transform = _transform;

	Perspective(45, 16.f / 9.f, 0.01f, 1000.f);
	LookAt(m_transform->Position(), math::Vec3f(0, 0, 0), math::Vector3<float>::Up());
}

PerspectiveCamera::PerspectiveCamera()
{
	m_transform = nullptr;
}

PerspectiveCamera::~PerspectiveCamera()
{

}

const math::Mat4& PerspectiveCamera::Perspective(float v, float r, float n, float f) //v = FOV, r = aspectRatio, n = near, f = far
{
	_projectionMatrix = math::Mat4(
	  n/r,				0,				0,				0,
		0,			  n/v,				0,				0,
		0,				0,	 -(f+n)/(f-n), -2*(f*n)/(f-n),
		0,				0,			   -1,				0);

	return _projectionMatrix;
}

const math::Mat4& PerspectiveCamera::LookAt(const math::Vec3f& _eye, const math::Vec3f& _target, const math::Vec3f& _up)
{
	math::Vec3f h(_target - _eye);
	h.Normalize();
	
	math::Vec3f f = math::CrossProduct(_up, h).Normalized();
	
	math::Vec3f g = math::CrossProduct(h, f); 	

	float fe = -math::DotProduct(f, _eye);
	float ge = -math::DotProduct(g, _eye);
	float he = -math::DotProduct(h, _eye);

	_viewMatrix = math::Mat4(	f.x, f.y, f.z, fe,
								g.x, g.y, g.z, ge,
								h.x, h.y, h.z, he,
								0.f, 0.f, 0.f, 1);
	return _viewMatrix;
}

} // namespace gfx
} // namespace pad