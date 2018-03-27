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

	bool					isWireframe;
};

} // namespace rhi
} // namespace gfx
} // namespace pad