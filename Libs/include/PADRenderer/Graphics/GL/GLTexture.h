#pragma once
#include <Graphics/RHI/ATexture.h>

namespace pad	{
namespace gfx	{
namespace gl	{

class GLTexture final : public rhi::ATexture
{
public:
	GLTexture() = default;
	~GLTexture() = default;

public:
	void GenerateID() override;
	void Bind() override;
};

} // namespace gl
} // namespace gfx
} // namespace pad
