#pragma once
#include <Graphics/Window/WindowSettings.h>

namespace pad	{
namespace gfx	{
namespace win	{

enum class E_WINDOW_TYPE : uint8
{
	ENGINE = 1,
	EDITOR = 2
};

class IWindowBase
{
protected:
	bool m_isOpen;

public:
	virtual void PollEvents() = 0;
	virtual void Resize(const math::Vec2<uint16>& size) = 0;
	virtual void ReloadSettings(const WindowSettings& _infos) = 0;
	virtual void Init(const WindowSettings& _infos) = 0;
	virtual bool IsOpen() = 0;
	virtual void SwapBuffer() = 0;

public:
	virtual const math::Vec2i GetPosition() const = 0;
	virtual const math::Vec2i GetSize() const = 0;
};

} // namespace win
} // namespace gfx
} // namespace pad