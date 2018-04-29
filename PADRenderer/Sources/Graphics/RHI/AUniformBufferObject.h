#pragma once
#include <Common.h>
#include <Graphics/RHI/AVertexArray.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

class AUniformBufferObject : public AVertexArray
{
public:
	virtual ~AUniformBufferObject() = default;

public:
	virtual void InitializeBufferData(const int32 _dataSize) = 0;
	virtual void BindData(const int32 _size, const int32 _offset, const void* const _data) = 0;
};

} // namespace rhi
} // namespace gfx
} // namespace pad