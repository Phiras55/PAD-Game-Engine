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

void GLShaderProgram::SetUniform(const std::string& name, int32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1i(m_uniforms[name], value);
}

void GLShaderProgram::SetUniform(const std::string& name, uint32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1ui(m_uniforms[name], value);
}

void GLShaderProgram::SetUniform(const std::string& name, float32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1f(m_uniforms[name], value);
}

void GLShaderProgram::SetUniform(const std::string& name, bool value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniform1i(m_uniforms[name], (int)value);
}

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad