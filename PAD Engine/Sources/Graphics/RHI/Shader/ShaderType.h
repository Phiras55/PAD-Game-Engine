#pragma once
#include <Common.h>

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

enum class E_SHADER_TYPE : uint8
{
	VERTEX,
	FRAGMENT
};

enum class E_VERTEX_ATTRIB_LOCATION : uint8
{
	POSITION	= 0,
	COLOR		= 1,
	UV			= 2,
	NORMAL		= 3
};

}  // namespace shad
}  // namespace rhi
}  // namespace gfx
}  // namespace pad