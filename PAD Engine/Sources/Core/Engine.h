#include <Core/EngineClock.h>
#include <System/SDLWindow.h>
#include <Graphics/RHI/IRenderer.h>
#include <Graphics/RHI/RenderSettings.h>

namespace pad	{
namespace core	{

class Engine final
{
public:
	Engine();
	~Engine();

	Engine(const Engine&)  = delete;
	Engine(const Engine&&) = delete;

private:
	gfx::rhi::IRenderer*	mp_renderer;															/*! The renderer that contains the window and is used to render data. */
	sys::SDLWindow*			mp_window;

public:
	void InitSimulation();																			/*! Initialize the simulation. Reads the config files and initialize the renderer and the window. */
	void StartSimulation();																			/*! Starts the simulation with the parameters given in InitSimulation method. */
	void PollEvents();
	void Update();
	void FixedUpdate();
	void Render();

	void CreateWindow(const sys::WindowSettings& _infos);
	void CreateRenderer(const gfx::rhi::ContextSettings& _settings);

	void Draw(const gfx::mod::Mesh& _m, const gfx::rhi::RenderSettings& _settings);
	void SwapBuffers();
	void ClearBuffer();
	void ResizeContext(const uint32 _w, const uint32 _h);

	void FlushLogs();
	bool IsWindowOpen();

public:
	void operator=(const Engine&)	= delete;
	void operator=(const Engine&&)	= delete;
};

} // namespace core
} // namespace pad