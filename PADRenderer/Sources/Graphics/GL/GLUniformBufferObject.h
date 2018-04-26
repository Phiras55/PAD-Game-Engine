#pragma once
#include <Graphics/RHI/AUniformBufferObject.h>

namespace pad	{
namespace gfx	{
namespace gl	{

class GLUniformBufferObject final : public rhi::AUniformBufferObject
{
public:
	GLUniformBufferObject();
	~GLUniformBufferObject();

public:
	void BindData(const int32 _size, const int32 _offset, void* const _data)	override;
	void InitializeBufferData(const int32 _dataSize)							override;
	void GenerateID()															override;
	void Bind()																	override;
	void Unbind()																override;
};

}  // namespace gl
}  // namespace gfx
}  // namespace pad