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
	}

	void SDLWindow::Init(const Win_Info& _infos)
	{
		mp_window = SDL_CreateWindow(_infos.title.c_str(), 
			_infos.posX, 
			_infos.posY, 
			_infos.width, 
			_infos.height, 
			SDL_WINDOW_OPENGL | 
			SDL_WINDOW_RESIZABLE | 
			(_infos.isFullscreen ? SDL_WINDOW_FULLSCREEN : 0x00));

		if (mp_window)
			m_isOpen = true;
	}

	void SDLWindow::Resize(const int _w, const int _h)
	{

	}

	void SDLWindow::ReloadInformations(const Win_Info& _infos)
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