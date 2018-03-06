#pragma once
#include <SDL.h>

#include <System/IWindowBase.h>

namespace pad
{
namespace sys
{

class SDLWindow final : public IWindowBase
{
public:
	SDLWindow();
	virtual ~SDLWindow();

	SDLWindow(const SDLWindow&)	= delete;
	SDLWindow(SDLWindow&&)		= delete;

private:
	SDL_Window* mp_window;
	SDL_Event	m_event;

public:
	virtual void Init(const Win_Info& _infos);
	virtual void PollEvents();
	virtual void Resize(const int _w, const int _h);
	virtual void ReloadInformations(const Win_Info& _infos);

	inline virtual bool IsOpen() { return m_isOpen; }

	void SwapBuffer();

public:
	inline SDL_Window* const GetWindow() { return mp_window; }

	inline const int GetPositionX() { int x;  SDL_GetWindowPosition(mp_window, &x, nullptr); return x; }
	inline const int GetPositionY() { int y;  SDL_GetWindowPosition(mp_window, nullptr, &y); return y; }
	inline const int GetSizeX()		{ int x;  SDL_GetWindowSize(mp_window, &x, nullptr); return x; }
	inline const int GetSizeY()		{ int y;  SDL_GetWindowSize(mp_window, nullptr, &y); return y; }

public:
	SDLWindow & operator=(const SDLWindow&) = delete;
	SDLWindow& operator=(SDLWindow&&)		 = delete;
};

} // namespace sys
} // namespace pad