#include <Common.h>
#include <Core/Engine.h>
#include <Core/Timer.h>
#include <Graphics/GL/GLRenderer.h>
#include <Math/Matrix4x4.h>
#include <Logger/SimpleLogger.h>

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

void Engine::InitSimulation(const gfx::rhi::ContextSettings& _c, const gfx::win::WindowSettings& _w)
{
	LOG_INIT();
	core::EngineClock::Init();
	m_highLevelRenderer.Initialize(_c, _w);

#pragma region Mesh
	pad::gfx::mod::MeshData md;

	md.positions = new float[24]{
		-0.5, -0.5,  0.5,
		0.5, -0.5,  0.5,
		-0.5,  0.5,  0.5,
		0.5,  0.5, -0.5,
		-0.5, -0.5, -0.5,
		-0.5,  0.5, -0.5,
		0.5, -0.5, -0.5,
		0.5,  0.5,  0.5
	};
	md.positionCount = 24;

	md.indices = new pad::uint32[36]{
		0, 1, 2,
		3, 4, 5,
		4, 3, 6,
		7, 2, 1,
		4, 6, 1,
		4, 2, 5,
		7, 1, 6,
		5, 2, 7,
		4, 0, 2,
		6, 3, 7,
		1, 0, 4,
		7, 3, 5
	};
	md.indiceCount = 36;

	gfx::mod::Mesh* m = new gfx::mod::Mesh();

	m_highLevelRenderer.GenerateMesh(*m, md);
	m_resourceManager->GetMeshManager().AddResource("Cube", *m);
#pragma endregion

#pragma region Material
	gfx::mod::Material* mat = new gfx::mod::Material();

#pragma endregion
}

void Engine::StartSimulation()
{
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
	FixedUpdate();
	LateUpdate();

	Render();
}

void Engine::PollEvents()
{
	m_highLevelRenderer.PollEvents();
}

void Engine::Update()
{

}

void Engine::FixedUpdate()
{

}

void Engine::LateUpdate()
{

}

void Engine::Render()
{
	m_highLevelRenderer.Render(*m_resourceManager);
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