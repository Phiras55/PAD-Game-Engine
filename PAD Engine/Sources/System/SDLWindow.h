#pragma once
#include <SDL.h>

#include <System/IWindowBase.h>
#include <Math/Vector2.h>

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
	SDL_Window*		mp_window;
	SDL_GLContext	m_context;
	SDL_Event		m_event;

public:
	virtual void Init(const WindowSettings& _infos);
	virtual void PollEvents();
	virtual void Resize(const math::Vec2<uint16>& size);
	virtual void ReloadSettings(const WindowSettings& _infos);
	virtual void SwapBuffer();

	inline virtual bool IsOpen() { return m_isOpen; }

public:
	virtual inline const math::Vec2i GetPosition()	const	{ math::Vec2i v;  SDL_GetWindowPosition(mp_window, &v.x, &v.y); return v; }
	virtual inline const math::Vec2i GetSize()		const	{ math::Vec2i v;  SDL_GetWindowSize(mp_window, &v.x, &v.y); return v; }

public:
	SDLWindow& operator=(const SDLWindow&)	= delete;
	SDLWindow& operator=(SDLWindow&&)		= delete;
};

} // namespace sys
} // namespace pad