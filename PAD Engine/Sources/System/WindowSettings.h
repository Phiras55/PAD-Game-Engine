#pragma once
#include <string>

#include <Math/Vector2.h>
#include <System/WindowEnums.h>

namespace pad	{
namespace sys	{

struct WindowSettings final
{
	math::Vec2i		size;
	math::Vec2i		position;
	std::string		title;
	E_WINDOW_TYPE	windowType;

	bool			isFullscreen;
};

} // namespace sys
} // namespace pad