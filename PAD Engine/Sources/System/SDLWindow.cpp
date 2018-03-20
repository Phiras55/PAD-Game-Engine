#include <SDL.h>

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
		SDL_GL_DeleteContext(mp_context);
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

		mp_context = SDL_GL_CreateContext(mp_window);
		SDL_GL_MakeCurrent(mp_window, mp_context);
	}

	void SDLWindow::Resize(const math::Vec2<uint16>& _size)
	{

	}

	void SDLWindow::ReloadSettings(const WindowSettings& _infos)
	{

	}

	void SDLWindow::PollEvents()
	{
		SDL_Event events;
		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_QUIT)
				m_isOpen = false;
		}
	}

	void SDLWindow::SwapBuffer()
	{
		SDL_GL_SwapWindow(mp_window);
	}

	const math::Vec2i SDLWindow::GetPosition() const
	{ 
		math::Vec2i v;  
		SDL_GetWindowPosition(mp_window, &v.x, &v.y); 
		return v; 
	}

	const math::Vec2i SDLWindow::GetSize() const
	{
		math::Vec2i v;  
		SDL_GetWindowSize(mp_window, &v.x, &v.y); 
		return v; 
	}

} // namespace sys
} // namespace pad