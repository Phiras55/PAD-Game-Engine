#pragma once
#include <Common.h>
namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

enum class E_DATA_TYPE : uint8
{
	SAMPLER2D,
	VEC3,
	VEC4,
	MAT4,
	MAT4_ARRAY,
	FLOAT,
	INT,
	UINT,
	BOOL
};

using DataType = E_DATA_TYPE;

struct CustomUniform final
{
	void*		data;
	E_DATA_TYPE	type;
	uint32		count;
};

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad