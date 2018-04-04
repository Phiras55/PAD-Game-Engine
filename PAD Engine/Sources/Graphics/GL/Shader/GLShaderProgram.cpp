#include <GL/glew.h>
#include <Logger/SimpleLogger.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

GLShaderProgram::GLShaderProgram()
{
	m_id = SHADER_INVALID_VALUE;
}

GLShaderProgram::~GLShaderProgram()
{

}

bool GLShaderProgram::CompileProgram()
{
	int32 success;
	int32& vertID = m_vertShader->GetID();
	int32& fragID = m_fragShader->GetID();

	m_id = glCreateProgram();
	glAttachShader(m_id, vertID);
	glAttachShader(m_id, fragID);
	glLinkProgram(m_id);

	glGetProgramiv(m_id, GL_LINK_STATUS, &success);

	if (!success)
	{
		char infoLog[SHADER_LOG_SIZE];

		glDeleteProgram(m_id);
		glDeleteShader(vertID);
		glDeleteShader(fragID);
		glGetProgramInfoLog(m_id, SHADER_LOG_SIZE, NULL, infoLog);
		LOG_ERROR("Error! Could not link the program: %%", infoLog);
		return false;
	}

	glDetachShader(m_id, vertID);
	glDetachShader(m_id, fragID);
	glDeleteShader(vertID);
	glDeleteShader(fragID);

	return true;
}

void GLShaderProgram::Use()
{
	if (m_id != SHADER_INVALID_VALUE && m_id != m_currentUsedID)
	{
		m_currentUsedID = m_id;
		glUseProgram(m_id);
	}
}

void GLShaderProgram::SetUniform(const std::string& name, const int32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1i(m_uniforms[name], value);
}

void GLShaderProgram::SetUniform(const std::string& name, const uint32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1ui(m_uniforms[name], value);
}

void GLShaderProgram::SetUniform(const std::string& name, const float32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1f(m_uniforms[name], value);
}

void GLShaderProgram::SetUniform(const std::string& name, const bool value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1i(m_uniforms[name], (int)value);
}

void GLShaderProgram::SetUniform(const std::string& name, math::Mat4& _value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniformMatrix4fv(m_uniforms[name], 1, GL_TRUE, _value[0]);
}

void GLShaderProgram::SetUniform(const std::string& name, const math::Vec4f& _value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform4fv(m_uniforms[name], 1, &_value[0]);
}

void GLShaderProgram::SetUniform(const std::string& name, const math::Vec3f& _value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform3fv(m_uniforms[name], 1, &_value[0]);
}

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad