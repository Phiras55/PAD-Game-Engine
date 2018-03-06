#pragma once
#include <iostream>

#include <System/SDLWindow.h>
#include <System/IModule.h>

namespace pad
{
namespace gfx
{

enum class E_WINDOW_TYPE : uint8
{
	ENGINE = 1,
	EDITOR = 2
};

class Renderer final : public sys::IModule
{
public:
	Renderer();
	virtual ~Renderer() = default;

	Renderer(const Renderer&)	= delete;
	Renderer(Renderer&&)		= delete;

private:
	sys::SDLWindow*	mp_window;
	SDL_GLContext	m_context;

public:
	virtual void StartModule();
	virtual void StopModule();

	void Init(const sys::Win_Info& _infos, const E_WINDOW_TYPE _windowType);
	void ClearScreen();
	void SwapBuffer();

private:
	void CreateContext(const sys::Win_Info& _infos);
	void InitContext();
	void InitViewPort();

public:
	inline sys::SDLWindow* GetWindow() { return mp_window; }

public:
	void operator=(const Renderer&) = delete;
	void operator=(Renderer&&)		= delete;
};

} // namespace gfx
} // namespace pad