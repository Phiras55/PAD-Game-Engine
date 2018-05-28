#pragma once
#include <System/Scene/Scene.h>
#include <System/ResourceHandling/MasterManager.h>
#include <Graphics/RHI/IRenderer.h>
#include <Graphics/Window/AWindow.h>

namespace pad	{
namespace gfx	{

#define MAX_JOINT_COUNT 150
#define FLOAT_PER_MATRIX 16

class HighLevelRenderer final
{
public:
	HighLevelRenderer();
	virtual ~HighLevelRenderer();

	HighLevelRenderer(const HighLevelRenderer&) = delete;
	HighLevelRenderer(HighLevelRenderer&&)		= delete;

private:
	rhi::IRenderer*				m_lowLevelRenderer;
	win::AWindow*				m_mainWindow;
	sys::res::MasterManager*	m_masterManagerHandle;
	float						m_animJoints[MAX_JOINT_COUNT][FLOAT_PER_MATRIX];

public:
	void Initialize(
		const rhi::ContextSettings& _rSettings, 
		const win::WindowSettings& _wSettings, 
		sys::res::MasterManager* _masterManagerHandle);
	void Render(
		sys::res::MasterManager& _resources, 
		sys::ecs::Scene& _scene,
		sys::res::ComponentsHandler& _components);
	void GenerateMesh(gfx::mod::Mesh& _m, const gfx::mod::MeshData& _md);
	void PollEvents();
	void ResizeContext(const uint32 _w, const uint32 _h);
	bool IsWindowOpen();
	void GenerateTexture(	
		rhi::ATexture* const _texture,
		const std::string& _path,
		const rhi::TextureParameters& _param);
	bool LoadShaders(
		const std::string& _vPath,
		const std::string& _fPath,
		const std::string& _name);
	void BindInputs(
		const uint32 _key, 
		const inp::alias::Function& _func, 
		const bool _isToggleKey, 
		const float32 _cooldown);

	void CenterMouse();
	void CloseWindow();

private:
	void ClearBuffers();
	void SwapBuffers();
	void InitializeDefaultMeshes();
	void GetAnimMatrix(sys::ecs::AnimRenderer& _animRenderer, float(*_matrixArray)[FLOAT_PER_MATRIX], sys::res::MasterManager& _resources);
	void DrawStaticObjects(sys::res::MasterManager& _resources, sys::ecs::Scene& _scene, sys::res::ComponentsHandler& _components);
	void DrawAnimatedObjects(sys::res::MasterManager& _resources, sys::ecs::Scene& _scene, sys::res::ComponentsHandler& _components);
	void UnbindTextures(rhi::RenderSettings& _settings, const mod::Material& _mat, sys::res::MasterManager& _resources);
	void FillTextureLayout(rhi::RenderSettings& _settings, const mod::Material& _mat, sys::res::MasterManager& _resources);

public:
	inline win::AWindow* const GetMainWindow() const { return m_mainWindow; }

public:
	void operator=(const HighLevelRenderer&)	= delete;
	void operator=(HighLevelRenderer&&)			= delete;
};

} // namespace gfx
} // namespace pad