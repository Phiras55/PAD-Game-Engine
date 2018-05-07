#pragma once
#include <Graphics/RHI/Shader/AShader.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

class GLFragmentShader final : public rhi::shad::AShader
{
public:
	GLFragmentShader();
	virtual ~GLFragmentShader();

	GLFragmentShader(const GLFragmentShader&) = delete;
	GLFragmentShader(GLFragmentShader&&) = delete;

public:
	bool LoadShader(const char* _path) override;

private:
	bool CompileShader(const char* _shaderCode) override;

public:
	void operator=(const GLFragmentShader&) = delete;
	void operator=(GLFragmentShader&&) = delete;
};

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad