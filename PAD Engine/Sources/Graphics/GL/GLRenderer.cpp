#include <Graphics/GL/GLRenderer.h>
#include <Logger/SimpleLogger.h>
#include <Utilities/EnumUtils.h>
#include <GL/glew.h>

namespace pad	{
namespace gfx	{
namespace gl	{

GLRenderer::GLRenderer()
{

}

void GLRenderer::StopModule()
{

}

void GLRenderer::StartModule()
{

}

void GLRenderer::Init(const rhi::ContextSettings& _settings)
{
	InitContext(_settings);
	InitViewPort(_settings.viewportSize);
}

void GLRenderer::InitContext(const rhi::ContextSettings& _settings)
{
	if (glewInit() != GLEW_OK)
	{
		LOG_FATAL_S("Could not init glew!\n");
		return;
	}

	glClearColor(
		_settings.clearColor.r,
		_settings.clearColor.g,
		_settings.clearColor.b,
		_settings.clearColor.a);

	glewExperimental = true;

	if (util::IsFlagSet(_settings.enabledBuffers, gfx::rhi::E_BUFFER_TYPE::DEPTH_BUFFER))
	{
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
	}

	if (util::IsFlagSet(_settings.enabledBuffers, gfx::rhi::E_BUFFER_TYPE::STENCIL_BUFFER))
	{
		glEnable(GL_STENCIL_TEST);
		glStencilMask(0x00);
	}

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void GLRenderer::InitViewPort(const math::Vec2i& _viewportSize)
{
	glViewport(
		0, 
		0,
		_viewportSize.x,
		_viewportSize.y);
}

void GLRenderer::Draw(const mod::Mesh& _mesh, const rhi::RenderSettings& _settings)
{
	glBindVertexArray(_mesh.GetVertexArrayID());

	if (_settings.programs)
	{
		rhi::shad::AShaderProgram* currentShader = _settings.programs[0];
		if (currentShader)
		{
			currentShader->Use();
			glDrawElements(GL_TRIANGLES, _mesh.GetIndiceCount(), GL_UNSIGNED_INT, nullptr);
		}
	}
	else
	{
		LOG_ERROR_S("No valid shaders. Try to add one in the RenderSettings.\n");
	}
}

void GLRenderer::ClearBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GLRenderer::ResizeViewport(const uint32 _w, const uint32 _h)
{
	glViewport(0, 0, _w, _h);
	m_viewportSize.x = _w;
	m_viewportSize.y = _h;
}

void GLRenderer::InitBuffers()
{

}

void GLRenderer::GenerateBuffer(uint32& _id)
{

}

} // namespace gl
} // namespace gfx
} // namespace pad