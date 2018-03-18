#pragma once
#include <Graphics/RHI/Shader/AShaderProgram.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

class GLShaderProgram final : public rhi::shad::AShaderProgram
{
	GLShaderProgram();
	virtual ~GLShaderProgram();

	GLShaderProgram(const GLShaderProgram&) = delete;
	GLShaderProgram(GLShaderProgram&&) = delete;

public:
	virtual bool CompileProgram();
	virtual void Use();

	virtual void SetUniform(const std::string& name, int32 value);
	virtual void SetUniform(const std::string& name, uint32 value);
	virtual void SetUniform(const std::string& name, bool value);
	virtual void SetUniform(const std::string& name, float32 value);

public:
	void operator=(const GLShaderProgram&) = delete;
	void operator=(GLShaderProgram&&) = delete;
};

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad