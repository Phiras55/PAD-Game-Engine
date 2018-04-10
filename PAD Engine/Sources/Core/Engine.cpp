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

namespace pad	{
namespace core	{

Engine::Engine() :
	m_scene(new sys::ecs::Scene()),
	m_resourceManager(new sys::res::ResourceManager())
{

}

Engine::~Engine()
{
	if (m_scene)
		delete m_scene;
	if (mp_window)
		delete mp_window;
	if (mp_renderer)
		delete mp_renderer;
	if (m_resourceManager)
		delete m_resourceManager;
}

void Engine::InitSimulation(const gfx::rhi::ContextSettings& _c, const sys::win::WindowSettings& _w)
{
	LOG_INIT();
	core::EngineClock::Init();
	CreateWindow(_w);
	CreateRenderer(_c);

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
	
	//m->SetName("Cube");
	mp_renderer->GenerateMesh(md, m->GetVAO(), m->GetIBO());
	//m_resourceManager->GetMeshManager().AddResource("Cube", m);
	
	#pragma endregion
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
#pragma region Temp Code
	// TODO : Change the temp camera for a main camera in the scene
	sys::ecs::PerspectiveCamera cam;
	cam.Perspective(45.f, 16.f / 9.f, 0.01f, 1000.f);
	cam.LookAt(math::Vec3f(10, 10, -10), math::Vec3f(0, 0, 0), math::Vec3f::Up());

	math::Mat4 vp = cam.GetProjection() * cam.GetView();
#pragma endregion

	gfx::rhi::AVertexArray**	vaos		= nullptr;
	gfx::rhi::AVertexBuffer**	ibos		= nullptr;
	gfx::rhi::RenderSettings*	settings	= nullptr;

	uint32 meshCount		= (uint32)sys::ecs::MeshRenderer::GetCollection().size();
	uint32 meshRendererIdx	= 0;

	vaos		= new gfx::rhi::AVertexArray*[meshCount];
	ibos		= new gfx::rhi::AVertexBuffer*[meshCount];
	settings	= new gfx::rhi::RenderSettings[meshCount];

	for (const auto& meshRenderer : sys::ecs::MeshRenderer::GetCollection())
	{
		//const gfx::mod::Mesh& currentMesh = *m_resourceManager->GetMeshManager().GetResource(meshRenderer.GetMeshName());
		//vaos[meshRendererIdx]		= currentMesh.GetVAO();
		//ibos[meshRendererIdx]		= currentMesh.GetIBO();
		vaos[meshRendererIdx]		= nullptr;
		ibos[meshRendererIdx]		= nullptr;
		settings[meshRendererIdx]	= meshRenderer.GetSettings();

		++meshRendererIdx;
	}

	if (mp_renderer)
		mp_renderer->ForwardRendering(vaos, ibos, settings, vp, meshCount);

	delete[] vaos;
	delete[] ibos;
	delete[] settings;
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

void Engine::FlushLogs()
{
	LOG_FLUSH();
}

void Engine::GenerateMesh(gfx::mod::Mesh& _m, const gfx::mod::MeshData& _md)
{
	gfx::rhi::AVertexArray& vao		= *_m.GetVAO();
	gfx::rhi::AVertexBuffer& ibo	= *_m.GetIBO();

	if (mp_renderer)
		mp_renderer->GenerateMesh(_md, &vao, &ibo);
}

} // namespace core
} // namespace pad