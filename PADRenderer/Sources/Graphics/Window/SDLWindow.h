#pragma once
#include <Graphics/Window/AWindow.h>

namespace pad	{
namespace gfx	{
namespace win	{

class SDLWindow final : public AWindow
{
public:
	SDLWindow();
	virtual ~SDLWindow();

	SDLWindow(const SDLWindow&)																= delete;
	SDLWindow(SDLWindow&&)																	= delete;

private:
	struct SDL_Window*		mp_window;
	void*					mp_context;
	void*					mp_event;

public:
	void Init(const WindowSettings& _infos)																								override;
	void Close()																														override;
	void PollEvents()																													override;
	void Resize(const math::Vec2<uint16>& size)																							override;
	void ReloadSettings(const WindowSettings& _infos)																					override;
	void SwapBuffer()																													override;
	void UpdateInputs(const float32 _deltatime)																							override;
	void SetResizeCallback(const std::function<void(const uint32, const uint32)>& _func)												override;
	void BindInputs(const uint32 _key, const inp::alias::Function& _func, const bool _isToggleKey = false, const float32 _cooldown = 0)	override;
	void CenterMouse()																													override;
	const math::Vec2i GetMousePosition()																								override;

	inline bool IsOpen() override { return m_isOpen; }

public:
	const math::Vec2i GetPosition()	const  override;
	const math::Vec2i GetSize()		const  override;

public:
	SDLWindow& operator=(const SDLWindow&) = delete;
	SDLWindow& operator=(SDLWindow&&)	   = delete;
};

} // namespace win
} // namespace gfx
} // namespace pad