#pragma once
#include <map>
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
	~Shader();

	Shader(const Shader&)	= delete;
	Shader(Shader&&)		= delete;

private:
	static int32				 m_currentProgID;
	int32						 m_progID;
	std::map<std::string, int32> m_uniforms;

public:
	void Use();
	bool LoadFromFile(const char* _vPath, const char* _fPath);

	void SetUniform(const std::string& name, int32 value);
	void SetUniform(const std::string& name, uint32 value);
	void SetUniform(const std::string& name, bool value);
	void SetUniform(const std::string& name, float32 value);

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