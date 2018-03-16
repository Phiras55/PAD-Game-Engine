#pragma once
#include <Graphics/RHI/AVertexBuffer.h>

namespace pad {
namespace gfx {
namespace gl  {

class GLVertexElementBuffer final : public rhi::AVertexBuffer
{
public:
	GLVertexElementBuffer();
	virtual ~GLVertexElementBuffer();

public:
	virtual void GenerateID();
	virtual void Bind();
	virtual void BindData(uint32* const _data, const uint32 _dataSize);
	virtual void BindData(float* const _data, const uint32 _dataSize, const int32 _vertexElementCount, const uint8 _location) {}
};

} // namespace gl
} // namespace gfx
} // namespace pad