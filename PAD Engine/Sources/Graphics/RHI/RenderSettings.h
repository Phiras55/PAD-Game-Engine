#pragma once
#include <Math/Vector4.h>
#include <Math/Vector2.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

struct RenderSettings final
{
	math::Vec2i viewportSize;
	math::Vec4f clearColor;
};

} // namespace rhi
} // namesapce gfx
} // namesapce pad