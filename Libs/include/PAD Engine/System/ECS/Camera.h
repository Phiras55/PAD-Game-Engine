#pragma once
#include <Math/Matrix4x4.h>
#include <Utilities/Export.h>
#include <System/ECS/AComponent.h>

namespace pad	{
namespace sys	{
namespace ecs	{

class ENGINE_API Camera : public sys::ecs::AComponent
{
protected:
	math::Mat4		_projectionMatrix;
	math::Mat4		_viewMatrix;

public:
	virtual const math::Mat4& Perspective(float _fov, float _aspectRatio, float _near, float _far)				= 0;
	virtual const math::Mat4& LookAt(const math::Vec3f& eye, const math::Vec3f& center, const math::Vec3f& up)	= 0;

	virtual const alias::ComponentID GetType() const override
	{
		return static_cast<alias::ComponentID>(
			util::GetTypeID<std::remove_const_t<std::remove_reference_t<decltype(*this)>>>());
	}

public:
	inline const math::Mat4& GetProjection() const	{ return _projectionMatrix; }
	inline const math::Mat4& GetView()		 const	{ return _viewMatrix; }
};

} // namespace ecs
} // namespace sys
} // namespace pad