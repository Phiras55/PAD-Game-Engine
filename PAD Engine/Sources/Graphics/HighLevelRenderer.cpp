#include <EnginePCH.h>
#include <Graphics/HighLevelRenderer.h>
#include <Graphics/GL/GLRenderer.h>
#include <Graphics/Window/SDLWindow.h>
#include <System/ECS/PerspectiveCamera.h>
#include <System/ECS/MeshRenderer.h>
#include <Graphics/Model/Material.h>

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

void HighLevelRenderer::Initialize(const rhi::ContextSettings& _rSettings, const win::WindowSettings& _wSettings, sys::res::MasterManager* _masterManagerHandle)
{
	m_masterManagerHandle = _masterManagerHandle;

	switch (_wSettings.windowType)
	{
	case gfx::win::E_WINDOW_TYPE::SDL:
		m_mainWindow = new win::SDLWindow();
		break;
	case gfx::win::E_WINDOW_TYPE::QT:
		break;
	}

	switch (_rSettings.implementationType)
	{
	case rhi::E_RENDERER_IMPLEMENTATION_TYPE::OPENGL:
	default:
		m_lowLevelRenderer = new gl::GLRenderer();
	}

	if (m_mainWindow)
	{
		m_mainWindow->Init(_wSettings);
		m_mainWindow->SetResizeCallback(
			std::bind(
				&gfx::gl::GLRenderer::ResizeViewport,
				static_cast<gfx::gl::GLRenderer*>(m_lowLevelRenderer),
				std::placeholders::_1,
				std::placeholders::_2
			)
		);
	}

	if (m_lowLevelRenderer)
		m_lowLevelRenderer->Init(_rSettings);

	InitializeDefaultMeshes();
}

void HighLevelRenderer::InitializeDefaultMeshes()
{
	pad::gfx::mod::MeshData md1, md2;

	md1.positions		= new float32[24]{
		-0.5, -0.5,  0.5,
		 0.5, -0.5,  0.5,
		-0.5,  0.5,  0.5,
		 0.5,  0.5, -0.5,
		-0.5, -0.5, -0.5,
		-0.5,  0.5, -0.5,
		 0.5, -0.5, -0.5,
		 0.5,  0.5,  0.5
	};
	md1.positionCount	= 24;

	md1.indices			= new uint32[36]{
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
	md1.indiceCount		= 36;

	md1.uvs = new float32[16]{
		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0,

		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0,
	};
	md1.uvCount = 16;

	md2.positions		= new float32[12]{
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0,
		 0.5,  0.5, 0.0,
		-0.5,  0.5, 0.0
	};
	md2.positionCount	= 12;

	md2.indices			= new uint32[6]{
		0, 1, 2,
		0, 2, 3
	};
	md2.indiceCount		= 6;

	md2.uvs				= new float32[8]{
		0.0f, 0.0f,
		10.f, 0.0f,
		10.f, 10.f,
		0.0f, 10.f
	};
	md2.uvCount			= 8;

	gfx::mod::Mesh m1, m2;

	GenerateMesh(m1, md1);
	m_masterManagerHandle->GetMeshManager().AddResource("Cube", m1);

	GenerateMesh(m2, md2);
	m_masterManagerHandle->GetMeshManager().AddResource("Quad", m2);
}

void HighLevelRenderer::Render(sys::res::MasterManager& _resources, sys::ecs::Scene& _scene, sys::res::ComponentsHandler& _components)
{
	if (!m_lowLevelRenderer)
		return;

	const sys::ecs::PerspectiveCamera& cam = _scene.GetMainCamera();
	math::Mat4 vp = cam.GetProjection() * cam.GetView();

	ClearBuffers();

	m_lowLevelRenderer->SetCameraUniformBufferData(math::Vec3f(), math::Vec3f(), vp);

	std::list<sys::ecs::MeshRenderer*>* mr = _components.GetActiveComponents<sys::ecs::MeshRenderer>();

	if (mr)
	{
		for (auto& meshRenderer : *mr)
		{
			const gfx::mod::Mesh* const currentMesh		= _resources.GetMeshManager().GetResource(meshRenderer->GetMeshName());
			const gfx::mod::Material* const currentMat	= _resources.GetMaterialManager().GetResource(meshRenderer->GetMaterialName());
			gfx::rhi::RenderSettings& currentSettings	= meshRenderer->GetSettings();

			if (!currentMesh)
				continue;

			if (currentMat)
				FillTextureLayout(currentSettings, *currentMat, _resources);

			m_lowLevelRenderer->ForwardRendering(currentMesh->GetVAO(), currentMesh->GetIBO(), currentSettings, vp);

			if (currentMat)
				UnbindTextures(currentSettings, *currentMat, _resources);
		}
	}

	SwapBuffers();
}

void HighLevelRenderer::FillTextureLayout(rhi::RenderSettings& _settings, const mod::Material& _mat, sys::res::MasterManager& _resources)
{
	rhi::shad::CustomUniform uniform;
	rhi::ATexture** texture = _resources.GetTextureManager().GetResource(_mat.GetAlbedoMapName());

	if (texture)
	{
		(*texture)->Bind();
		uniform.data = (void*)&(*texture)->GetID();
		uniform.type = rhi::shad::DataType::UINT;

		_settings.customUniforms["albedoMap"] = uniform;

		(*texture)->Bind();
	}

	texture = _resources.GetTextureManager().GetResource(_mat.GetNormalMapName());
	if (texture)
	{
		(*texture)->Bind();
		uniform.data = (void*)&(*texture)->GetID();

		_settings.customUniforms["normalMap"] = uniform;
		uniform.type = rhi::shad::DataType::UINT;
	}

	uniform.data = (void*)&_mat.GetAlbedo();
	uniform.type = rhi::shad::DataType::VEC4;

	_settings.customUniforms["albedo"] = uniform;

	uniform.data = (void*)&_mat.GetAmbient();
	uniform.type = rhi::shad::DataType::VEC3;

	_settings.customUniforms["ambient"] = uniform;

	uniform.data = (void*)&_mat.GetDiffuse();
	uniform.type = rhi::shad::DataType::VEC3;

	_settings.customUniforms["diffuse"] = uniform;

	uniform.data = (void*)&_mat.GetSpecular();
	uniform.type = rhi::shad::DataType::VEC3;

	_settings.customUniforms["specular"] = uniform;

	uniform.data = (void*)&_mat.GetShiness();
	uniform.type = rhi::shad::DataType::FLOAT;

	_settings.customUniforms["shiness"] = uniform;
}

void HighLevelRenderer::UnbindTextures(rhi::RenderSettings& _settings, const mod::Material& _mat, sys::res::MasterManager& _resources)
{
	rhi::ATexture** texture = _resources.GetTextureManager().GetResource(_mat.GetAlbedoMapName());

	if (texture)
	{
		(*texture)->Unbind();
	}

	texture = _resources.GetTextureManager().GetResource(_mat.GetNormalMapName());
	if (texture)
	{
		(*texture)->Unbind();
	}
}

void HighLevelRenderer::GenerateMesh(gfx::mod::Mesh& _m, const gfx::mod::MeshData& _md)
{
	if (m_lowLevelRenderer)
		m_lowLevelRenderer->GenerateMesh(_md, _m.GetVAO(), _m.GetIBO());
}

bool HighLevelRenderer::IsWindowOpen()
{
	if (m_mainWindow)
		return m_mainWindow->IsOpen();
	return false;
}

void HighLevelRenderer::GenerateTexture(rhi::ATexture* const _texture, const std::string& _path, const rhi::TextureParameters& _param)
{
	if (m_lowLevelRenderer)
		m_lowLevelRenderer->GenerateTexture(_texture, _path, _param);
}

void HighLevelRenderer::PollEvents()
{
	if (m_mainWindow)
		m_mainWindow->PollEvents();
}

void HighLevelRenderer::ClearBuffers()
{
	if(m_lowLevelRenderer)
		m_lowLevelRenderer->ClearBuffer();
}

void HighLevelRenderer::SwapBuffers()
{
	if(m_mainWindow)
		m_mainWindow->SwapBuffer();
}

void HighLevelRenderer::ResizeContext(const uint32 _w, const uint32 _h)
{
	m_lowLevelRenderer->ResizeViewport(_w, _h);
}

} // namespace gfx
} // namespace pad