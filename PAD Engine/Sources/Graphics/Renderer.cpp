#include <Graphics/Renderer.h>

#include <GL/glew.h>

namespace pad
{
namespace gfx
{

	Renderer::Renderer()
	{

	}

	void Renderer::Init(const sys::Win_Info& _infos, const E_WINDOW_TYPE _windowType)
	{
		switch (_windowType)
		{
		case E_WINDOW_TYPE::EDITOR:
			mp_window = nullptr;
			break;
		case E_WINDOW_TYPE::ENGINE:
		default:
			mp_window = new sys::SDLWindow();
		}
		CreateContext(_infos);
	}

	void Renderer::StopModule()
	{
		if (mp_window)
		{
			SDL_GL_DeleteContext(m_context);
			delete mp_window;
			SDL_Quit();
		}
	}

	void Renderer::StartModule()
	{
		InitContext();
		InitViewPort();
	}

	void Renderer::CreateContext(const sys::Win_Info& _infos)
	{
		if (mp_window)
		{
			if (SDL_Init(SDL_INIT_VIDEO) < 0)
			{
				// TODO : Error message
				return;
			}

			mp_window->Init(_infos);
			m_context = SDL_GL_CreateContext(mp_window->GetWindow());
			SDL_GL_MakeCurrent(mp_window->GetWindow(), m_context);
		}

		if (glewInit() != GLEW_OK)
		{
			// TODO : Error message
			return;
		}

		glClearColor(
			_infos.background_color[0],
			_infos.background_color[1],
			_infos.background_color[2],
			_infos.background_color[3]);
	}

	void Renderer::InitContext()
	{
		glewExperimental = true;

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glDepthFunc(GL_LESS);
	}

	void Renderer::InitViewPort()
	{
		glViewport(
			mp_window->GetPositionX(), 
			mp_window->GetPositionY(),
			mp_window->GetSizeX(), 
			mp_window->GetSizeY());
	}

	void Renderer::ClearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::SwapBuffer()
	{
		mp_window->SwapBuffer();
	}

} // namespace gfx
} // namespace pad