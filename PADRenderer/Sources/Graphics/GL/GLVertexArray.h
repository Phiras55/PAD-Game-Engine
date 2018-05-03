#pragma once
#include <Graphics/RHI/AVertexArray.h>

namespace pad {
namespace gfx {
namespace gl  {

class GLVertexArray final : public rhi::AVertexArray
{
public:
	GLVertexArray();
	virtual ~GLVertexArray() = default;

public:
	void GenerateID()	override;
	void Bind()			override;
	void Unbind()		override;
};

} // namespace gl
} // namespace gfx
} // namespace pad