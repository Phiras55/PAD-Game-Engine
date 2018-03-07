#pragma once
#include <string>

#include <Common.h>
#include <Math/Vector2.h>
#include <Math/Vector4.h>

namespace pad
{
namespace sys
{

struct WindowSettings final
{
	math::Vec2i size;
	math::Vec2i position;
	std::string title;

	bool		isFullscreen;
};

} // namespace sys
} // namespace pad