#include <Core/Engine.h>

namespace pad
{
namespace core
{

Engine::Engine()
{

}

void Engine::InitSimulation()
{
	sys::Win_Info infos;

	infos.title			= "This is a SDL Window.";
	infos.posX			= 400u;
	infos.posY			= 200u;
	infos.width			= 800u;
	infos.height		= 600u;
	infos.isFullscreen	= false;

	infos.background_color[0] = 0.3f;
	infos.background_color[1] = 0.3f;
	infos.background_color[2] = 0.3f;
	infos.background_color[3] = 1.0f;

	m_renderer.Init(infos, gfx::E_WINDOW_TYPE::ENGINE);
	m_renderer.StartModule();
}

void Engine::StartSimulation()
{
	while (m_renderer.GetWindow()->IsOpen())
	{
		PollEvents();
		Update(1.f);
		FixedUpdate(1.f);
		Render();
	}
}

void Engine::PollEvents()
{
	m_renderer.GetWindow()->PollEvents();

	// Get inputs here
}

void Engine::Update(const float _deltaTime)
{
	
}

void Engine::FixedUpdate(const float _deltaTime)
{

}

void Engine::Render()
{
	m_renderer.ClearScreen();



	m_renderer.SwapBuffer();
}

}
}