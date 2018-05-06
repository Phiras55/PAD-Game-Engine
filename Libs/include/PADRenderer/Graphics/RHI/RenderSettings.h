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
		programHandle("Default"),
		modelMatrix(nullptr),
		isWireframe(false)
	{
	}

	std::string									programHandle;
	std::map<std::string, shad::CustomUniform>	customUniforms;
	const math::Matrix4x4*						modelMatrix;
	UniformBufferSettings						uniformSettings;

	bool isWireframe;
};

} // namespace rhi
} // namespace gfx
} // namespace pad