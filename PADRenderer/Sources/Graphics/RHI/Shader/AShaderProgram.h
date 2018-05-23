#pragma once
#include <PCH.h>
#include <Graphics/RHI/Shader/AShader.h>
#include <Graphics/RHI/Shader/CustomUniform.h>

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

class AShaderProgram
{
public:
	virtual ~AShaderProgram() = default;

protected:
	static int32 m_currentUsedID;

	int32	 m_id;
	AShader* m_vertShader;
	AShader* m_fragShader;
	std::map<std::string, int32> m_uniforms;

public:
	virtual bool CompileProgram() = 0;
	virtual void Use() = 0;

	virtual void SetUniform(const std::string& _name, const int32 value)							= 0;
	virtual void SetUniform(const std::string& _name, const uint32 value)							= 0;
	virtual void SetUniform(const std::string& _name, const bool value)								= 0;
	virtual void SetUniform(const std::string& _name, const float32 value)							= 0;
	virtual void SetUniform(const std::string& _name, const math::Vec4f& _value)					= 0;
	virtual void SetUniform(const std::string& _name, const math::Vec3f& _value)					= 0;
	virtual void SetUniform(const std::string& _name, float* const _value)							= 0;
	virtual void SetUniform(const std::string& _name, float* const _value, const uint32 _count)		= 0;
	virtual void SetCustomUniform(const std::string& _name, const CustomUniform& _customUniform)	= 0;

public:
	inline int32&		GetID()			{ return m_id; }
	inline const int32	GetID() const	{ return m_id; }

	inline AShader* const GetVertexShader()		const	{ return m_vertShader; }
	inline AShader* const GetFragmentShader()	const	{ return m_fragShader; }

	inline void SetVertexShader(AShader* const _vs)		{ m_vertShader = _vs; }
	inline void SetFragmentShader(AShader* const _fs)	{ m_fragShader = _fs; }
};

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad