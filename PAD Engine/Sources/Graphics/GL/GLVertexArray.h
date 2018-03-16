#pragma once
#include <Graphics/RHI/AVertexArray.h>

namespace pad {
namespace gfx {
namespace gl  {

class GLVertexArray final : public rhi::AVertexArray
{
public:
	virtual void GenerateID();
	virtual void Bind();
};

} // namespace gl
} // namespace gfx
} // namespace pad