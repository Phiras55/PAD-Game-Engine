#include <Graphics/HighLevelRenderer.h>
#include <Graphics/GL/GLRenderer.h>
#include <Graphics/Window/SDLWindow.h>
#include <System/ECS/PerspectiveCamera.h>
#include <System/ECS/MeshRenderer.h>

namespace pad	{
namespace gfx	{

HighLevelRenderer::HighLevelRenderer() :
	m_lowLevelRenderer(nullptr),
	m_mainWindow(nullptr)
{

}

HighLevelRenderer::~HighLevelRenderer()
{
	delete m_lowLevelRenderer;
	delete m_mainWindow;
}

void HighLevelRenderer::Initialize(const rhi::ContextSettings& _rSettings, const win::WindowSettings& _wSettings)
{
	switch (_rSettings.implementationType)
	{
	case rhi::E_RENDERER_IMPLEMENTATION_TYPE::OPENGL:
	default:
		m_lowLevelRenderer = new gl::GLRenderer();
	}

	m_mainWindow = new win::SDLWindow();
	m_mainWindow->Init(_wSettings);
}

void HighLevelRenderer::Render(const sys::res::MasterManager& _resources)
{
#pragma region Temp Code
	// TODO : Change the temp camera for a main camera in the scene
	sys::ecs::PerspectiveCamera cam;
	cam.Perspective(45.f, 16.f / 9.f, 0.01f, 1000.f);
	cam.LookAt(math::Vec3f(0, 15, -10), math::Vec3f(0, 0, 0), math::Vec3f::Up());

	math::Mat4 vp = cam.GetProjection() * cam.GetView();
#pragma endregion

	for (const auto& meshRenderer : sys::ecs::MeshRenderer::GetCollection())
	{
		const gfx::mod::Mesh& currentMesh = *_resources.GetMeshManager().GetResource(meshRenderer.GetMeshName());

		if (m_lowLevelRenderer)
			m_lowLevelRenderer->ForwardRendering(currentMesh.GetVAO(), currentMesh.GetIBO(), meshRenderer.GetSettings(), vp);
	}
}

} // namespace gfx
} // namespace pad