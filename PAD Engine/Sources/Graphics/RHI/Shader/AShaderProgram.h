#pragma once
#include <Math/Matrix4x4.h>
#include <Graphics/RHI/Shader/AShader.h>

namespace pad	{
namespace gfx	{
namespace rhi	{
namespace shad	{

class AShaderProgram
{
protected:
	static int32 m_currentUsedID;

	int32	 m_id;
	AShader* m_vertShader;
	AShader* m_fragShader;
	std::map<std::string, int32> m_uniforms;

public:
	ENGINE_API virtual bool CompileProgram() = 0;
	ENGINE_API virtual void Use() = 0;

	ENGINE_API virtual void SetUniform(const std::string& name, const int32 value) = 0;
	ENGINE_API virtual void SetUniform(const std::string& name, const uint32 value) = 0;
	ENGINE_API virtual void SetUniform(const std::string& name, const bool value) = 0;
	ENGINE_API virtual void SetUniform(const std::string& name, const float32 value) = 0;
	ENGINE_API virtual void SetUniform(const std::string& name, const math::Vec4f& _value) = 0;
	ENGINE_API virtual void SetUniform(const std::string& name, const math::Vec3f& _value) = 0;
	ENGINE_API virtual void SetUniform(const std::string& name, math::Mat4& _value) = 0;

public:
	ENGINE_API inline int32&		GetID()			{ return m_id; }
	ENGINE_API inline const int32	GetID() const	{ return m_id; }

	ENGINE_API inline AShader* const GetVertexShader()		const	{ return m_vertShader; }
	ENGINE_API inline AShader* const GetFragmentShader()	const	{ return m_fragShader; }

	ENGINE_API inline void SetVertexShader(AShader* const _vs)		{ m_vertShader = _vs; }
	ENGINE_API inline void SetFragmentShader(AShader* const _fs)	{ m_fragShader = _fs; }
};

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad