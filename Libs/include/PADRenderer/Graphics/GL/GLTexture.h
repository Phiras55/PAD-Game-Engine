#pragma once
#include <Graphics/RHI/ATexture.h>

namespace pad	{
namespace gfx	{
namespace gl	{

class GLTexture final : public rhi::ATexture
{
public:
	GLTexture();
	~GLTexture() = default;

public:
	void GenerateID() override;
	void Bind() override;
	void SetTextureParameters(const rhi::TextureParameters& _param) override;
	void GenerateTexture(const int32 _w, const int32 _h, uchar* const _data) override;

private:
	void CheckWrapParameters(const rhi::WrapType& _param, const rhi::AxisType& _axis);
	void CheckFilteringParameters(const rhi::TextureFiltering& _param, const rhi::AxisType& _axis);
	void CheckMipmapParameters(const rhi::MipmapType& _param, const rhi::AxisType& _axis);
};

} // namespace gl
} // namespace gfx
} // namespace pad
