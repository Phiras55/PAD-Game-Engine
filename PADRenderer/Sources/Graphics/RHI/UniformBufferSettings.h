#pragma once
#include <Common.h>
namespace pad	{
namespace gfx	{
namespace rhi	{

struct UniformBufferSettings final
{
	int32		dataSize;
	int32		bindingPointID;
	std::string name;
};

} // namespace rhi
} // namespace gfx
} // namespace pad