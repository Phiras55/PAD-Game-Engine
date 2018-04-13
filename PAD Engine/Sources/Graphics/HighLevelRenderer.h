#pragma once
#include <System/Resource/MasterManager.h>
#include <Graphics/RHI/IRenderer.h>
#include <Graphics/Window/AWindow.h>

namespace pad	{
namespace gfx	{

class HighLevelRenderer final
{
public:
	HighLevelRenderer();
	virtual ~HighLevelRenderer();

	HighLevelRenderer(const HighLevelRenderer&) = delete;
	HighLevelRenderer(HighLevelRenderer&&)		= delete;

private:
	rhi::IRenderer* m_lowLevelRenderer;
	win::AWindow*	m_mainWindow;

public:
	void Initialize(const rhi::ContextSettings& _rSettings, const win::WindowSettings& _wSettings);
	void Render(const sys::res::MasterManager& _resources); // Will also take the scene when and sort what needs to be rendered.

public:
	void operator=(const HighLevelRenderer&)	= delete;
	void operator=(HighLevelRenderer&&)			= delete;
};

} // namespace gfx
} // namespace pad