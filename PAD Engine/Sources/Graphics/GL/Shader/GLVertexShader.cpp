#include <sstream>

#include <GL/glew.h>
#include <Logger/SimpleLogger.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <Graphics/RHI/Shader/ShaderInfos.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

GLVertexShader::GLVertexShader()
{
	m_id = SHADER_INVALID_VALUE;
}

GLVertexShader::~GLVertexShader()
{
	if (m_id != SHADER_INVALID_VALUE)
		glDeleteShader(m_id);
}

bool GLVertexShader::LoadShader(const char* _path)
{
	std::string shaderCode;
	std::ifstream shaderFile;

	shaderFile.open(_path);

	if (!shaderFile.is_open())
	{
		LOG_ERROR("Error! Could not open file: %%\n", _path);
		return false;
	}

	std::stringstream stream;

	stream << shaderFile.rdbuf();
	shaderFile.close();
	shaderCode = stream.str();

	const char* ptrCode = shaderCode.c_str();

	if (!CompileShader(ptrCode))
	{
		return false;
	}

	return true;
}

bool GLVertexShader::CompileShader(const char* _shaderCode)
{
	int32 success;

	m_id = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(m_id, 1, &_shaderCode, NULL);
	glCompileShader(m_id);

	glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[SHADER_LOG_SIZE];

		glDeleteShader(m_id);
		glGetShaderInfoLog(m_id, SHADER_LOG_SIZE, NULL, infoLog);
		LOG_ERROR("Error! Could not compile shader: %%\n", infoLog);
		return false;
	}

	return true;
}

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad