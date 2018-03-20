#pragma once
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
	struct SDL_Window*		mp_window;
	void*					mp_context;

public:
	virtual void Init(const WindowSettings& _infos);
	virtual void PollEvents();
	virtual void Resize(const math::Vec2<uint16>& size);
	virtual void ReloadSettings(const WindowSettings& _infos);
	virtual void SwapBuffer();

	inline virtual bool IsOpen() { return m_isOpen; }

public:
	virtual const math::Vec2i GetPosition()	const;
	virtual const math::Vec2i GetSize()		const;

public:
	SDLWindow& operator=(const SDLWindow&)	= delete;
	SDLWindow& operator=(SDLWindow&&)		= delete;
};

} // namespace sys
} // namespace pad