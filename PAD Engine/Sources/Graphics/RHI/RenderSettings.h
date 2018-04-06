#pragma once
#include <vector>

#include <Math/Vector4.h>
#include <Graphics/RHI/Shader/AShaderProgram.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

struct RenderSettings
{
	RenderSettings() :
		modelMatrix(nullptr),
		isWireframe(false)
	{
		programs.reserve(1);
	}

	std::vector<shad::AShaderProgram*>	programs;
	const math::Matrix4x4*				modelMatrix;

	bool isWireframe;
};

} // namespace rhi
} // namespace gfx
} // namespace pad