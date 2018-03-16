#pragma once
#include <Graphics/RHI/Shader/AShader.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

class GLVertexShader final : public rhi::shad::AShader
{
public:
	GLVertexShader();
	virtual ~GLVertexShader();

public:
	virtual bool LoadShader(const char* _path);
	virtual bool CompileShader(const char* _shaderCode);
};

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad