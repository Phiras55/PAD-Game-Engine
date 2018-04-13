#pragma once
#include <string>

#include <Common.h>
#include <Math/Vector2.h>

namespace pad	{
namespace gfx	{
namespace win	{

enum class E_WINDOW_TYPE : uint8
{
	SDL = 0x01,
	QT = 0x02
};

struct WindowSettings final
{
	math::Vec2i		size;
	math::Vec2i		position;
	std::string		title;
	E_WINDOW_TYPE	windowType;

	bool			isFullscreen;
};

} // namespace win
} // namespace gfx
} // namespace pad