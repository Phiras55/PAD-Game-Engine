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
		isWireframe(false)
	{
		shaders.reserve(1);
	}

	std::vector<shad::AShaderProgram*> shaders;

	bool toTexture;
	bool isWireframe;
};

} // namespace rhi
} // namespace gfx
} // namespace pad