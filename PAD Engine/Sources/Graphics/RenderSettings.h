#pragma once
#include <Math/Vector4.h>
#include <Math/Vector2.h>

namespace pad
{
namespace gfx
{

struct RenderSettings final
{
	math::Vec2i viewportSize;
	math::Vec4f clearColor;
};

} //namesapce gfx
} //namesapce pad