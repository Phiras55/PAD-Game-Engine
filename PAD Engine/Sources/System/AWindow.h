#pragma once

#include <functional>
#include <System/WindowSettings.h>

namespace pad	{
namespace sys	{

class AWindow
{
protected:
	std::function<void(const uint32, const uint32)>	m_resizeCallback;
	bool m_isOpen;

public:
	virtual void SetResizeCallback(const std::function<void(const uint32, const uint32)>& _func) = 0;
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

} // namespace sys
} // namespace pad