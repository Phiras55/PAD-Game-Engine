#pragma once
#include <Graphics/RHI/Shader/AShaderManager.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

class GLShaderManager final : public rhi::shad::AShaderManager
{
public:
	GLShaderManager();
	~GLShaderManager();

public:
	bool LoadShaders(const std::string& _vertPath, const std::string& _fragPath, const std::string& _name) override;
	rhi::shad::AShaderProgram* const GetShader(const std::string& _name) override;


};

} // namespace shad
} // namespace gl
} // namespace gfx
} // namespace pad