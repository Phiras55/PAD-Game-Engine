#include <PCH.h>
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
	glDeleteProgram(m_id);
}

bool GLShaderProgram::CompileProgram()
{
	if (!m_vertShader || !m_fragShader)
		return false;

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
		m_vertShader = nullptr;
		m_fragShader = nullptr;
		return false;
	}

	glDetachShader(m_id, vertID);
	glDetachShader(m_id, fragID);
	glDeleteShader(vertID);
	glDeleteShader(fragID);
	m_vertShader = nullptr;
	m_fragShader = nullptr;
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

void GLShaderProgram::SetUniform(const std::string& name, const math::Mat4& _value)
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

void GLShaderProgram::SetUniform(const std::string& name, const float(*_value)[16], const uint32 _count)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_id, name.c_str());
	glUniformMatrix4fv(m_uniforms[name], _count, GL_TRUE, _value[0]);
}

void GLShaderProgram::SetCustomUniform(const std::string& _name, const rhi::shad::CustomUniform& _customUniform)
{
	if (m_uniforms.find(_name) == m_uniforms.end())
		m_uniforms[_name] = glGetUniformLocation(m_id, _name.c_str());

	switch (_customUniform.type)
	{
	case rhi::shad::DataType::SAMPLER2D:

		break;
	case rhi::shad::DataType::MAT4:
		SetUniform(_name, *static_cast<float*>(_customUniform.data));
		break;
	case rhi::shad::DataType::MAT4_ARRAY:
		SetUniform(_name, static_cast<float(*)[16]>(_customUniform.data), _customUniform.count);
		break;
	case rhi::shad::DataType::VEC4:
		SetUniform(_name, *static_cast<math::Vec4f*>(_customUniform.data));
		break;
	case rhi::shad::DataType::VEC3:
		SetUniform(_name, *static_cast<math::Vec3f*>(_customUniform.data));
		break;
	case rhi::shad::DataType::FLOAT:
		SetUniform(_name, *static_cast<float32*>(_customUniform.data));
		break;
	case rhi::shad::DataType::INT:
		SetUniform(_name, *static_cast<int32*>(_customUniform.data));
		break;
	case rhi::shad::DataType::UINT:
		SetUniform(_name, *static_cast<uint32*>(_customUniform.data));
		break;
	case rhi::shad::DataType::BOOL:
		SetUniform(_name, *static_cast<bool*>(_customUniform.data));
		break;
	default:
		LOG_ERROR_S("Error trying to set a custom uniform. An unexpected DataType was chosen.\n");
	}
}

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad