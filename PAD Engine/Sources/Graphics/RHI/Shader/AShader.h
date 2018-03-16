#pragma once
#include <Common.h>

#include <string>
#include <map>

#define SHADER_LOG_SIZE 512
#define SHADER_INVALID_VALUE 0

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

class AShader
{
protected:
	int32 m_id;
	std::map<std::string, int32> m_uniforms;

public:
	virtual bool LoadShader(const char* _path) = 0;
	virtual bool CompileShader(const char* _shaderCode) = 0;

	virtual void SetUniform(const std::string& name, int32 value)	= 0;
	virtual void SetUniform(const std::string& name, uint32 value)	= 0;
	virtual void SetUniform(const std::string& name, bool value)	= 0;
	virtual void SetUniform(const std::string& name, float32 value) = 0;

public:
	inline int32&		GetID()			{ return m_id; }
	inline const int32	GetID() const	{ return m_id; }
};

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad