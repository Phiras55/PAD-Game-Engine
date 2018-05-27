#pragma once
#include <Common.h>
#include <Json/Serialization.h>
#include <Graphics/RHI/Shader/AShaderProgram.h>
#include <Graphics/RHI/UniformBufferSettings.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

struct RenderSettings final : public ISerializable
{
	RenderSettings() :
		programHandle("Default"),
		modelMatrix(nullptr),
		isAffectedByLight(false),
		isWireframe(false)
	{
	}

	std::string												programHandle;
	std::unordered_map<std::string, shad::CustomUniform>	customUniforms;
	const math::Matrix4x4*									modelMatrix;
	
	bool isAffectedByLight;
	bool isWireframe;

	json Serialize()				override
	{
		json j;

		AddDataToJson(j, "programHandle", programHandle);
		AddDataToJson(j, "isWireframe", isWireframe);

		return j;
	}
	
	void Deserialize(const json& j)	override
	{
		programHandle	= JsonToData<std::string>(j, "programHandle");
		isWireframe		= JsonToData<bool>(j, "isWireframe");
	}
};

} // namespace rhi
} // namespace gfx
} // namespace pad