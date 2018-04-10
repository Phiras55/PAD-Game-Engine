#pragma once
#include <Graphics/RHI/Shader/AShaderProgram.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

class GLShaderProgram final : public rhi::shad::AShaderProgram
{
public:
	GLShaderProgram();
	virtual ~GLShaderProgram();

	GLShaderProgram(const GLShaderProgram&) = delete;
	GLShaderProgram(GLShaderProgram&&)		= delete;

public:
	bool CompileProgram()	override;
	void Use()				override;

	void SetUniform(const std::string& name, const int32 value)			override;
	void SetUniform(const std::string& name, const uint32 value)		override;
	void SetUniform(const std::string& name, const bool value)			override;
	void SetUniform(const std::string& name, const float32 value)		override;
	void SetUniform(const std::string& name, const math::Mat4& _value)	override;
	void SetUniform(const std::string& name, const math::Vec4f& _value)	override;
	void SetUniform(const std::string& name, const math::Vec3f& _value)	override;

public:
	void operator=(const GLShaderProgram&)	= delete;
	void operator=(GLShaderProgram&&)		= delete;
};

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad