#include <System/SDLWindow.h>

namespace pad
{
namespace sys
{

	SDLWindow::SDLWindow()
	{

	}

	SDLWindow::~SDLWindow()
	{
		SDL_DestroyWindow(mp_window);
		SDL_GL_DeleteContext(m_context);
		SDL_Quit();
	}

	void SDLWindow::Init(const WindowSettings& _infos)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			// TODO : Error message
			return;
		}

		mp_window = SDL_CreateWindow(_infos.title.c_str(), 
			_infos.position.x,
			_infos.position.y,
			_infos.size.x, 
			_infos.size.y, 
			SDL_WINDOW_OPENGL | 
			SDL_WINDOW_RESIZABLE | 
			(_infos.isFullscreen ? SDL_WINDOW_FULLSCREEN : 0x00));

		m_isOpen = true;

		m_context = SDL_GL_CreateContext(mp_window);
		SDL_GL_MakeCurrent(mp_window, m_context);
	}

	void SDLWindow::Resize(const math::Vec2<uint16>& _size)
	{

	}

	void SDLWindow::ReloadSettings(const WindowSettings& _infos)
	{

	}

	void SDLWindow::PollEvents()
	{
		while (SDL_PollEvent(&m_event))
		{
			if (m_event.type == SDL_QUIT)
				m_isOpen = false;
		}
	}

	void SDLWindow::SwapBuffer()
	{
		SDL_GL_SwapWindow(mp_window);
	}

} // namespace sys
} // namespace pad