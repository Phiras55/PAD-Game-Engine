#include <Core/Engine.h>
#include <Core/Timer.h>
#include <Graphics/GL/GLRenderer.h>
#include <Math/Matrix4x4.h>

namespace pad	{
namespace core	{

Engine::Engine()
{
	math::Matrix4x4 mat1;
	mat1.IsOrthogonal();
}

Engine::~Engine()
{
	delete mp_window;
}

void Engine::InitSimulation()
{
	// Will be read from a config file
	sys::WindowSettings winSettings;

	winSettings.title = "This is a SDL Window.";
	winSettings.position.x = 400u;
	winSettings.position.y = 200u;
	winSettings.size.x = 800u;
	winSettings.size.y = 600u;
	winSettings.isFullscreen = false;

	// Will be read from a config file
	sys::E_WINDOW_TYPE windowType = sys::E_WINDOW_TYPE::ENGINE;

	// Will be read from a config file
	gfx::rhi::RenderSettings renderSettings;

	renderSettings.viewportSize.x = winSettings.size.x;
	renderSettings.viewportSize.y = winSettings.size.y;
	renderSettings.clearColor.r = 0.3f;
	renderSettings.clearColor.g = 0.3f;
	renderSettings.clearColor.b = 0.3f;
	renderSettings.clearColor.a = 1.0f;

	CreateWindow(winSettings, windowType);
	CreateRenderer(renderSettings);

	core::EngineClock::Init();
}

void Engine::StartSimulation()
{
	while (mp_window->IsOpen())
	{
		core::EngineClock::Update();
		PollEvents();

		if (true)
		{
			Update();
			FixedUpdate();
		}

		Render();
	}
}

void Engine::PollEvents()
{
	mp_window->PollEvents();
	LOG_FLUSH();
}

void Engine::Update()
{
	core::Timer::PauseAll();
}

void Engine::FixedUpdate()
{

}

void Engine::Render()
{
	m_renderer->ClearBuffer();

	gfx::mod::Mesh m;
	m_renderer->Draw(m);

	mp_window->SwapBuffer();
}

void Engine::CreateWindow(const sys::WindowSettings& _infos, const sys::E_WINDOW_TYPE _windowType)
{
	switch (_windowType)
	{
	case sys::E_WINDOW_TYPE::EDITOR:
		mp_window = nullptr;
		break;
	case sys::E_WINDOW_TYPE::ENGINE:
	default:
		mp_window = new sys::SDLWindow();
	}

	mp_window->Init(_infos);
}

void Engine::CreateRenderer(const gfx::rhi::RenderSettings& settings)
{
	m_renderer = new gfx::gl::GLRenderer();
	m_renderer->Init(settings);
}

} // namespace core
} // namespace pad