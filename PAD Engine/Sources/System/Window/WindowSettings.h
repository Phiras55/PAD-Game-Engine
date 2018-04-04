#pragma once

#include <string>
#include <Math/Vector2.h>
#include <System/Window/WindowEnums.h>

namespace pad	{
namespace sys	{
namespace win	{

struct WindowSettings final
{
	math::Vec2i		size;
	math::Vec2i		position;
	std::string		title;
	E_WINDOW_TYPE	windowType;

	bool			isFullscreen;
};

} // namespace win
} // namespace sys
} // namespace pad