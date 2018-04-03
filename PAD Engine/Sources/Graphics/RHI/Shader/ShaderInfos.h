#pragma once
#include <Common.h>

#include <Math/Vector4.h>

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

enum class E_SHADER_TYPE : uint8
{
	VERTEX,
	FRAGMENT
};

using ShaderType = E_SHADER_TYPE;

enum class E_VERTEX_ATTRIB_LOCATION : uint8
{
	POSITION	= 0,
	COLOR		= 1,
	UV			= 2,
	NORMAL		= 3
};

using AttribLocation = E_VERTEX_ATTRIB_LOCATION;

struct ShaderUniformData
{
	math::Vec4f cameraPos;
};

}  // namespace shad
}  // namespace rhi
}  // namespace gfx
}  // namespace pad