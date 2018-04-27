#pragma once
#include <Common.h>
#include <Graphics/RHI/Shader/AShaderProgram.h>
#include <Graphics/RHI/UniformBufferSettings.h>

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

	std::vector<shad::AShaderProgram*>			programs;
	std::map<std::string, shad::CustomUniform>	customUniforms;
	const math::Matrix4x4*						modelMatrix;
	UniformBufferSettings						uniformSettings;

	bool isWireframe;
};

} // namespace rhi
} // namespace gfx
} // namespace pad