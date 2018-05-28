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

	m_highLevelRenderer.Initialize(_c, _w, m_resourceManager);

	sys::ecs::PADObject::SetComponentHandler(&m_componentHandler);
}

void Engine::StartSimulation()
{
	m_scene->Init();
	m_physicContext->Init();
	m_scene->Start();
	m_fixedUpdateTimer.Start();

	m_scene->SetLightRotation(math::Vec3f(0.f, 45.f, 0.f));

	sys::ecs::PerspectiveCamera* c = m_scene->GetMainCamera();
	math::Transform& t = c->GetOwner()->GetTransform();

	m_highLevelRenderer.BindInputs(SDLK_w,		std::bind(&sys::ecs::PerspectiveCamera::MoveForward, c), false, 0);
	m_highLevelRenderer.BindInputs(SDLK_s,		std::bind(&sys::ecs::PerspectiveCamera::MoveBackward, c), false, 0);
	m_highLevelRenderer.BindInputs(SDLK_a,		std::bind(&sys::ecs::PerspectiveCamera::MoveLeft, c), false, 0);
	m_highLevelRenderer.BindInputs(SDLK_d,		std::bind(&sys::ecs::PerspectiveCamera::MoveRight, c), false, 0);
	m_highLevelRenderer.BindInputs(SDLK_e,		std::bind(&sys::ecs::PerspectiveCamera::MoveUp, c), false, 0);
	m_highLevelRenderer.BindInputs(SDLK_q,		std::bind(&sys::ecs::PerspectiveCamera::MoveDown, c), false, 0);
	m_highLevelRenderer.BindInputs(SDLK_ESCAPE, std::bind(&Engine::Close, this), true, 0);
	m_highLevelRenderer.BindInputs(SDLK_F1,		std::bind(&Engine::ToggleDirectionalLightRotation, this), true, 0);
	m_highLevelRenderer.BindInputs(SDLK_F5,		std::bind(&Engine::SaveCurrentScene, this, "scene.json"), true, 0);
	m_highLevelRenderer.BindInputs(SDLK_F9,		std::bind(&Engine::LoadScene, this, "scene.json"), true, 0);

	core::EngineClock::Init();

	while (m_highLevelRenderer.IsWindowOpen())
	{
		Simulate(true);
	}
}

void Engine::Simulate(bool _stepPhys)
{
	core::EngineClock::Update();
	PollEvents();
	FlushLogs();

	Update();

	if (_stepPhys && m_fixedUpdateTimer.GetDuration() >= (1.f / 60.f))
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
	if (m_scene)
	{
		m_scene->Update();
		if (m_scene->GetMainCamera() && m_highLevelRenderer.GetMainWindow())
		{
			m_scene->GetMainCamera()->FirstPersonMouseInput(
				m_highLevelRenderer.GetMainWindow()->GetMousePosition(),
				m_highLevelRenderer.GetMainWindow()->GetSize());
			m_highLevelRenderer.CenterMouse();
		}

	}
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

void Engine::SaveCurrentScene(const std::string& _savePath)
{
	if (m_scene)
		m_scene->Serialize(_savePath);
}

void Engine::LoadScene(const std::string& _savePath)
{
	if (m_scene)
		delete m_scene;

	m_scene = new sys::ecs::Scene();
	m_scene->Deserialize(_savePath);
	m_scene->Init();
	m_scene->Start();
}

void Engine::ToggleDirectionalLightRotation()
{
	if (m_scene)
		m_scene->ToggleDirectionalLightRotation();
}

} // namespace core
} // namespace pad