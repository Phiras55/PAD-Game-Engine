#pragma once
#include <string>
#include <Common.h>

namespace pad
{
namespace sys
{

struct Win_Info
{
	// TODO : Change for vec2
	int16		width;
	int16		height;

	// TODO : Change for vec2
	int16		posX;
	int16		posY;

	// TODO : Change for vec4
	float		background_color[4];

	std::string title;

	bool		isFullscreen;
};

} // namespace sys
} // namespace pad