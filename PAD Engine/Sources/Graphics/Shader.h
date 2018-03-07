#pragma once
#include <Common.h>

#include <Graphics/ShaderType.h>

namespace pad
{
namespace gfx
{

class Shader
{
public:
	Shader();
	~Shader() = default;

	Shader(const Shader&)	= delete;
	Shader(Shader&&)		= delete;

private:
	static int32	m_currentProgID;
	int32			m_progID;

public:
	void Use();
	bool LoadFromFile(const char* _vPath, const char* _fPath);

private:
	bool CompileShader(const char* _shaderCode, int32& _shaderID, const E_SHADER_TYPE& _type);
	bool LoadShader(const char* _path, const E_SHADER_TYPE& _type, int32& _shaderID);
	bool CreateProgram(const int32 _vertID, const int32 _fragID);

public:
	void operator=(const Shader&)	= delete;
	void operator=(Shader&&)		= delete;
};

} // namespace gfx
} // namespace pad