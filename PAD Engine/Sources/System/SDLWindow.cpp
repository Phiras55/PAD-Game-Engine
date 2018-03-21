#include <SDL2/SDL.h>

#include <Logger/SimpleLogger.h>
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
		if (mp_event)
			delete mp_event;

		SDL_DestroyWindow(mp_window);
		SDL_GL_DeleteContext(mp_context);
		SDL_Quit();
	}

	void SDLWindow::Init(const WindowSettings& _infos)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			LOG_FATAL_S("Error! Could not init SDL.\n");
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

		mp_event = new SDL_Event();
	}

	void SDLWindow::Resize(const math::Vec2<uint16>& _size)
	{
		if(mp_window)
			SDL_SetWindowSize(mp_window, _size.x, _size.y);
	}

	void SDLWindow::ReloadSettings(const WindowSettings& _infos)
	{

	}

	void SDLWindow::PollEvents()
	{
		SDL_Event* events = static_cast<SDL_Event*>(mp_event);
		while (SDL_PollEvent(events))
		{
			if (events->type == SDL_QUIT)
				m_isOpen = false;
			else if (events->type == SDL_WINDOWEVENT_RESIZED)
				m_resizeCallback(events->window.data1, events->window.data2);
		}
	}

	void SDLWindow::SetResizeCallback(const std::function<void(const uint32, const uint32)>& _func)
	{
		m_resizeCallback = _func;
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