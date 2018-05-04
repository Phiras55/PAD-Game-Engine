#include <PCH.h>
#include <Graphics/GL/Shader/GLShaderManager.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>

namespace pad	{
namespace gfx	{
namespace gl	{
namespace shad	{

GLShaderManager::GLShaderManager()
{

}

GLShaderManager::~GLShaderManager()
{

}

bool GLShaderManager::LoadShaders(const std::string& _vertPath, const std::string& _fragPath, const std::string& _name)
{
	pad::gfx::gl::shad::GLShaderProgram*		program = nullptr;
	pad::gfx::gl::shad::GLFragmentShader		fragShader;
	pad::gfx::gl::shad::GLVertexShader			vertShader;

	if (!vertShader.LoadShader(_vertPath.c_str()) || !fragShader.LoadShader(_fragPath.c_str()))
		return false;

	program = new gl::shad::GLShaderProgram();

	if (!program->CompileProgram())
		return false;

	auto it = m_shaders.find(_name);
	if (it != m_shaders.end())
	{
		delete it->second;
	}

	m_shaders[_name] = program;
	return true;
}

rhi::shad::AShaderProgram* const GLShaderManager::GetShader(const std::string& _name)
{
	auto it = m_shaders.find(_name);
	if (it != m_shaders.end())
	{
		return it->second;
	}
	return nullptr;
}

} // namespace shad
} // namespace rhi
} // namespace gfx
} // namespace pad