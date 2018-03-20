#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

#include <Graphics/Shader/Shader.h>

#define LOG_SIZE 512u
#define INVALID_PROG_VALUE 0u

namespace pad	{
namespace gfx	{

int32 Shader::m_currentProgID = INVALID_PROG_VALUE;

Shader::Shader()
	: m_progID(INVALID_PROG_VALUE)
{

}

Shader::~Shader()
{
}

void Shader::Use()
{
	if (m_progID != INVALID_PROG_VALUE && m_progID != m_currentProgID)
	{
		m_currentProgID = m_progID;
		glUseProgram(m_progID);
	}
}

bool Shader::LoadFromFile(const char* _vPath, const char* _fPath)
{
	if (!_vPath || !_fPath)
		return false;

	int32 vertID, fragID;

	if (!LoadShader(_vPath, E_SHADER_TYPE::VERTEX, vertID) || !LoadShader(_fPath, E_SHADER_TYPE::FRAGMENT, fragID))
		return false;

	if (!CreateProgram(vertID, fragID))
		return false;

	glFlush();

	return true;
}

bool Shader::LoadShader(const char* _path, const E_SHADER_TYPE& _type, int32& _shaderID)
{
	std::string shaderCode;
	std::ifstream shaderFile;

	shaderFile.open(_path);

	if (!shaderFile.is_open())
	{
		// TODO : Error message
		return false;
	}

	std::stringstream stream;

	stream << shaderFile.rdbuf();
	shaderFile.close();
	shaderCode = stream.str();

	const char* ptrCode = shaderCode.c_str();

	if (!CompileShader(ptrCode, _shaderID, _type))
	{
		return false;
	}

	return true;
}

bool Shader::CompileShader(const char* _shaderCode, int32& _shaderID, const E_SHADER_TYPE& _type)
{
	int32 success;
		
	_shaderID = (_type == E_SHADER_TYPE::VERTEX ? 
		glCreateShader(GL_VERTEX_SHADER) : 
		glCreateShader(GL_FRAGMENT_SHADER));

	glShaderSource(_shaderID, 1, &_shaderCode, NULL);
	glCompileShader(_shaderID);

	glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[LOG_SIZE];

		glDeleteShader(_shaderID);
		glGetShaderInfoLog(_shaderID, LOG_SIZE, NULL, infoLog);
		// TODO : Error message
		return false;
	}

	return true;
}

bool Shader::CreateProgram(const int32 _vertID, const int32 _fragID)
{
	int32 success;

	m_progID = glCreateProgram();
	glAttachShader(m_progID, _vertID);
	glAttachShader(m_progID, _fragID);
	glLinkProgram(m_progID);

	glGetProgramiv(m_progID, GL_LINK_STATUS, &success);

	if (!success)
	{
		char infoLog[LOG_SIZE];

		glDeleteProgram(m_progID);
		glDeleteShader(_vertID);
		glDeleteShader(_fragID);
		glGetProgramInfoLog(m_progID, LOG_SIZE, NULL, infoLog);
		// TODO : Error message
		return false;
	}

	glDetachShader(m_progID, _vertID);
	glDetachShader(m_progID, _fragID);
	glDeleteShader(_vertID);
	glDeleteShader(_fragID);

	return true;
}

void Shader::SetUniform(const std::string& name, int32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_progID, name.c_str());
	glUniform1i(m_uniforms[name], value);
}

void Shader::SetUniform(const std::string& name, uint32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_progID, name.c_str());
	glUniform1ui(m_uniforms[name], value);
}

void Shader::SetUniform(const std::string& name, float32 value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_progID, name.c_str());
	glUniform1f(m_uniforms[name], value);
}

void Shader::SetUniform(const std::string& name, bool value)
{
	if (m_uniforms.find(name) == m_uniforms.end())
		m_uniforms[name] = glGetUniformLocation(m_progID, name.c_str());
	glUniform1i(m_uniforms[name], (int)value);
}

} // namespace gfx
} // namespace pad