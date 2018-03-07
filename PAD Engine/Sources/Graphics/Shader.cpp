#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

#include <Graphics/Shader.h>

#define LOG_SIZE 512u

namespace pad
{
namespace gfx
{

	Shader::Shader()
	{

	}

	bool Shader::LoadFromFile(const char* _vPath, const char* _fPath)
	{
		int32 vertID, fragID;

		if (!LoadShader(_vPath, E_SHADER_TYPE::VERTEX, vertID) || !LoadShader(_fPath, E_SHADER_TYPE::FRAGMENT, fragID))
		{
			return false;
		}

		if (!CreateProgram(vertID, fragID))
		{
			return false;
		}

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

		if (!CreateShader(ptrCode, _shaderID, _type))
		{
			return false;
		}

		return true;
	}

	bool Shader::CreateShader(const char* _shaderCode, int32& _shaderID, const E_SHADER_TYPE& _type)
	{
		int32 success;
		
		_shaderID = (_type == E_SHADER_TYPE::VERTEX ? 
			glCreateShader(GL_VERTEX_SHADER) : 
			glCreateShader(GL_FRAGMENT_SHADER));

		glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			char infoLog[LOG_SIZE];

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

			glGetProgramInfoLog(m_progID, LOG_SIZE, NULL, infoLog);
			// TODO : Error message
			return false;
		}

		glDeleteShader(_vertID);
		glDeleteShader(_fragID);

		return true;
	}

} // namespace gfx
} // namespace pad