#pragma once
#include <Math/Matrix4x4.h>
#include <Utilities/Export.h>

namespace pad	{
namespace gfx	{

class ENGINE_API Camera
{
protected:
	Camera()	= default;
	~Camera()	= default;

protected:
	math::Mat4 _projectionMatrix;
	math::Mat4 _viewMatrix;

public:
	inline const math::Mat4& GetProjection()	{ return _projectionMatrix; }
	inline const math::Mat4& GetView()			{ return _viewMatrix; }
};

} // namespace gfx
} // namespace pad