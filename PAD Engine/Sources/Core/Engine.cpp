#include <EnginePCH.h>
#include <Core/Engine.h>
#include <Core/Timer.h>
#include <Graphics/GL/GLRenderer.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <System/ECS/MeshRenderer.h>
#include <System/ECS/PerspectiveCamera.h>
#include <System/Physics/BulletContext.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <System/ECS/MeshRenderer.h>
#include <System/ECS/PerspectiveCamera.h>
#include <Graphics/Model/Skeleton.h>

namespace pad	{
namespace core	{

sys::phx::IPhysicContext* Engine::m_physicContext = new sys::phx::BulletContext();

Engine::Engine() :
	m_scene(new sys::ecs::Scene()),
	m_resourceManager(new sys::res::MasterManager())
{

}

Engine::~Engine()
{
	if (m_scene)
		delete m_scene;
	if (m_resourceManager)
		delete m_resourceManager;
}

void Engine::Close()
{
	m_highLevelRenderer.CloseWindow();
}

void Engine::InitSimulation(const gfx::rhi::ContextSettings& _c, const gfx::win::WindowSettings& _w)
{
	LOG_INIT();
	core::EngineClock::Init();

	m_highLevelRenderer.Initialize(_c, _w, m_resourceManager);

	sys::ecs::PADObject::SetComponentHandler(&m_componentHandler);
}

void Engine::StartSimulation()
{
	m_scene->Init();
	m_physicContext->Init();
	m_scene->Start();
	m_fixedUpdateTimer.Start();

	sys::ecs::PerspectiveCamera* c = m_scene->GetMainCamera();
	math::Transform& t = c->GetTransform();

	m_highLevelRenderer.BindInputs(SDLK_w, std::bind(&sys::ecs::PerspectiveCamera::MoveForward, c, 5.f), false, 0);
	m_highLevelRenderer.BindInputs(SDLK_ESCAPE, std::bind(&Engine::Close, this), false, 0);

	while (m_highLevelRenderer.IsWindowOpen())
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

	if (m_fixedUpdateTimer.GetDuration() >= (1.f / 60.f))
	{
		m_fixedUpdateTimer.Reset();
		FixedUpdate();
	}

	LateUpdate();

	Render();
}

void Engine::PollEvents()
{
	m_highLevelRenderer.PollEvents();
}

void Engine::Update()
{
	m_scene->Update();
	m_highLevelRenderer.CenterMouse();
}

void Engine::FixedUpdate()
{
	m_physicContext->Update();
	m_scene->FixedUpdate();
}

void Engine::LateUpdate()
{

}

void Engine::Render()
{
	m_highLevelRenderer.Render(*m_resourceManager, *m_scene, m_componentHandler);
}

void Engine::ResizeContext(const uint32 _w, const uint32 _h)
{
	m_highLevelRenderer.ResizeContext(_w, _h);
}

void Engine::FlushLogs()
{
	LOG_FLUSH();
}

} // namespace core
} // namespace pad