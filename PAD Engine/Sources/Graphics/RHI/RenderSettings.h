#pragma once
#include <Math/Vector4.h>
#include <Graphics/RHI/Shader/AShaderProgram.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

struct RenderSettings
{
	shad::AShaderProgram**	programs;
	uint16					programCount;

	math::Vec4f				outlineColor;
	math::Vec3f				scale;
	float32					outlineThickness;
	bool					isOutlined;

	bool					isWireframe;
};

} // namespace rhi
} // namespace gfx
} // namespace pad