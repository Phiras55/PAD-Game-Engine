#pragma once
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
	virtual bool CompileProgram() = 0;
	virtual void Use() = 0;

	virtual void SetUniform(const std::string& name, int32 value) = 0;
	virtual void SetUniform(const std::string& name, uint32 value) = 0;
	virtual void SetUniform(const std::string& name, bool value) = 0;
	virtual void SetUniform(const std::string& name, float32 value) = 0;

public:
	inline int32&		GetID()			{ return m_id; }
	inline const int32	GetID() const	{ return m_id; }

	inline AShader* const GetVertexShader() const	{ return m_vertShader; }
	inline AShader* const GetFragmentShader() const { return m_fragShader; }
};

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad