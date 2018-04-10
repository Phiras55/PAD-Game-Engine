#pragma once
#include <Graphics/RHI/AVertexArray.h>

namespace pad {
namespace gfx {
namespace gl  {

class GLVertexArray final : public rhi::AVertexArray
{
public:
	void GenerateID() override;
	void Bind() override;
};

} // namespace gl
} // namespace gfx
} // namespace pad