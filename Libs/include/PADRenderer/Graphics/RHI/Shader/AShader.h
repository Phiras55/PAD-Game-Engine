#pragma once
#define SHADER_LOG_SIZE 512
#define SHADER_INVALID_VALUE 0

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

class AShader
{
public:
	virtual ~AShader() = default;

protected:
	int32 m_id;

public:
	virtual bool LoadShader(const char* _path) = 0;

protected:
	virtual bool CompileShader(const char* _shaderCode) = 0;

public:
	inline int32&		GetID()			{ return m_id; }
	inline const int32	GetID() const	{ return m_id; }
};

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad