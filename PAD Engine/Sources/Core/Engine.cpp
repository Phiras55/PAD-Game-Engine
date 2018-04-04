#include <Common.h>
#include <Core/Engine.h>
#include <Core/Timer.h>
#include <Graphics/GL/GLRenderer.h>
#include <Math/Matrix4x4.h>
#include <Logger/SimpleLogger.h>

namespace pad	{
namespace core	{

Engine::Engine() :
	m_scene(new sys::ecs::Scene())
{

}

Engine::~Engine()
{
	if (m_scene)
		delete m_scene;
	if(mp_window)
		delete mp_window;
	if (mp_renderer)
		delete mp_renderer;
}

void Engine::InitSimulation(const gfx::rhi::ContextSettings& _c, const sys::win::WindowSettings& _w)
{
	LOG_INIT();
	core::EngineClock::Init();
	CreateWindow(_w);
	CreateRenderer(_c);
}

void Engine::StartSimulation()
{
	while (mp_window->IsOpen())
	{
		Simulate();
	}
}

void Engine::Simulate()
{
	core::EngineClock::Update();
	PollEvents();
	FlushLogs();

	Update();
	FixedUpdate();
	LateUpdate();

	ClearBuffers();
	Render();
	SwapBuffers();
}

void Engine::PollEvents()
{
	if(mp_window)
		mp_window->PollEvents();
}

void Engine::Update()
{
	core::Timer::PauseAll();
}

void Engine::FixedUpdate()
{

}

void Engine::LateUpdate()
{

}

void Engine::Render()
{

}

void Engine::CreateWindow(const sys::win::WindowSettings& _infos)
{
	if (_infos.windowType == sys::win::E_WINDOW_TYPE::SDL)
		mp_window = new sys::win::SDLWindow();

	if(mp_window)
		mp_window->Init(_infos);
}

void Engine::CreateRenderer(const gfx::rhi::ContextSettings& _settings)
{
	mp_renderer = new gfx::gl::GLRenderer();
	mp_renderer->Init(_settings);

	if (mp_window)
	{
		mp_window->SetResizeCallback(
			std::bind(
				&gfx::gl::GLRenderer::ResizeViewport,
				static_cast<gfx::gl::GLRenderer*>(mp_renderer),
				std::placeholders::_1,
				std::placeholders::_2
			)
		);
	}
}

void Engine::ClearBuffers()
{
	if (mp_renderer)
		mp_renderer->ClearBuffer();
}

void Engine::SwapBuffers()
{
	if (mp_window)
		mp_window->SwapBuffer();
}

void Engine::ResizeContext(const uint32 _w, const uint32 _h)
{
	if (mp_renderer)
		mp_renderer->ResizeViewport(_w, _h);
}

void Engine::Draw(const gfx::mod::Mesh& _m, const gfx::rhi::RenderSettings& _settings, math::Mat4& _vp)
{
	if (mp_renderer)
		mp_renderer->Draw(_m, _settings, _vp);
}

void Engine::FlushLogs()
{
	LOG_FLUSH();
}

void Engine::GenerateMesh(gfx::mod::Mesh& _m, const gfx::mod::MeshData& _md)
{
	if (mp_renderer)
		mp_renderer->GenerateMesh(_m, _md);
}

} // namespace core
} // namespace pad