#include <Graphics/GL/GLRenderer.h>
#include <Logger/SimpleLogger.h>
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

void GLRenderer::Init(const rhi::RenderSettings& _settings)
{
	InitContext(_settings.clearColor);
	InitViewPort(_settings.viewportSize);
}

void GLRenderer::InitContext(const math::Vec4f& _clearColor)
{
	if (glewInit() != GLEW_OK)
	{
		LOG_FATAL_S("Could not init glew!\n");
		return;
	}

	glClearColor(
		_clearColor.r,
		_clearColor.g,
		_clearColor.b,
		_clearColor.a);

	glewExperimental = true;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glDepthFunc(GL_LESS);
}

void GLRenderer::InitViewPort(const math::Vec2i& _viewportSize)
{
	glViewport(
		0, 
		0,
		_viewportSize.x,
		_viewportSize.y);
}

void GLRenderer::Draw(const mod::Mesh& _mesh)
{
	glBindVertexArray(_mesh.GetVertexArrayID());
	glDrawElements(GL_TRIANGLES, _mesh.GetIndiceCount(), GL_UNSIGNED_INT, nullptr);
}

void GLRenderer::ClearBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLRenderer::ResizeViewport(const uint32 _w, const uint32 _h)
{
	glViewport(0, 0, _w, _h);
}

} // namespace gl
} // namespace gfx
} // namespace pad