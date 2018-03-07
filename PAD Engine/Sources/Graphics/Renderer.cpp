#include <Graphics/Renderer.h>

#include <GL/glew.h>

namespace pad
{
namespace gfx
{

	Renderer::Renderer()
	{

	}

	void Renderer::StopModule()
	{

	}

	void Renderer::StartModule()
	{

	}

	void Renderer::Init(const RenderSettings& settings)
	{
		InitContext(settings.clearColor);
		InitViewPort(settings.viewportSize);
	}

	void Renderer::InitContext(const math::Vec4f& _clearColor)
	{
		if (glewInit() != GLEW_OK)
		{
			// TODO : Error message
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

	void Renderer::InitViewPort(const math::Vec2i& _viewportSize)
	{
		glViewport(
			0, 
			0,
			_viewportSize.x,
			_viewportSize.y);
	}

	void Renderer::Draw()
	{

	}

	void Renderer::ClearBuffer()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

} // namespace gfx
} // namespace pad