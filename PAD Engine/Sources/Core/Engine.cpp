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
	if(mp_window)
		delete mp_window;
	if (mp_renderer)
		delete mp_renderer;
	if (m_resourceManager)
		delete m_resourceManager;
	if (m_physicContext)
		delete m_physicContext;
}

void Engine::InitSimulation(const gfx::rhi::ContextSettings& _c, const sys::win::WindowSettings& _w)
{
	LOG_INIT();
	core::EngineClock::Init();
	CreateWindow(_w);
	CreateRenderer(_c);

	#pragma region Mesh

	//gfx::gl::shad::GLShaderProgram	program;
	//gfx::gl::shad::GLFragmentShader	fragShader;
	//gfx::gl::shad::GLVertexShader	vertShader;

	//vertShader.LoadShader("../Resources/Shaders/basicPositions.vert");
	//fragShader.LoadShader("../Resources/Shaders/basicColors.frag");

	//program.SetVertexShader(&vertShader);
	//program.SetFragmentShader(&fragShader);
	//program.CompileProgram();

	//gfx::rhi::RenderSettings r;
	//r.shaders.push_back(&program);
	//r.isWireframe = true;

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
	m->SetName("Cube");
	mp_renderer->GenerateMesh(*m, md);
	m_resourceManager->GetMeshManager().AddResource(m->GetName(), *m);

	#pragma endregion
}

void Engine::StartSimulation()
{
	m_scene->Init();

	m_fixedUpdateTimer.Start();
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

	if (m_fixedUpdateTimer.GetDuration() > 0.016f)
	{
		FixedUpdate();
		m_fixedUpdateTimer.ResetDuration();
	}

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
	m_scene->Update();
}

void Engine::FixedUpdate()
{
	m_physicContext->Update();
	m_scene->FixedUpdate();
}

void Engine::LateUpdate()
{
	m_scene->LateUpdate();
}

void Engine::Render()
{
	sys::ecs::PerspectiveCamera cam;
	cam.Perspective(45.f, 16.f / 9.f, 0.01f, 1000.f);
	cam.LookAt(math::Vec3f(0, 0, 10), math::Vec3f(0, 0, 0), math::Vec3f::Up());

	math::Mat4 mvp = cam.GetProjection() * cam.GetView();

	gfx::gl::shad::GLShaderProgram	program;
	gfx::gl::shad::GLFragmentShader	fragShader;
	gfx::gl::shad::GLVertexShader	vertShader;

	vertShader.LoadShader("../Resources/Shaders/basicPositions.vert");
	fragShader.LoadShader("../Resources/Shaders/basicColors.frag");

	program.SetVertexShader(&vertShader);
	program.SetFragmentShader(&fragShader);
	program.CompileProgram();

	gfx::rhi::RenderSettings r;
	r.shaders.push_back(&program);
	r.isWireframe = true;

	for (auto mr : sys::ecs::MeshRenderer::GetCollection())
	{
		math::Mat4 mvp = cam.GetProjection() * cam.GetView() * mr.GetOwner()->GetTransform().GetLocalTransform();

		if (mp_renderer)
			mp_renderer->Draw(*m_resourceManager->GetMeshManager().GetResource(mr.GetMeshName()), r, mvp);
	}
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