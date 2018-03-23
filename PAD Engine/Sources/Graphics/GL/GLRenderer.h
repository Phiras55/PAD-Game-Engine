#pragma once
#include <iostream>

#include <Graphics/RHI/ContextSettings.h>
#include <Graphics/RHI/RenderSettings.h>
#include <Graphics/RHI/IRenderer.h>

namespace pad	{
namespace gfx	{
namespace gl	{

class GLRenderer final : public rhi::IRenderer
{
public:
	GLRenderer();
	virtual ~GLRenderer() = default;

	GLRenderer(const GLRenderer&)	= delete;
	GLRenderer(GLRenderer&&)		= delete;

public:
	virtual void StartModule();
	virtual void StopModule();

	virtual void Init(const rhi::ContextSettings& _settings);
	virtual void Draw(const mod::Mesh& _mesh, const rhi::RenderSettings& _settings);
	virtual void ResizeViewport(const uint32 _w, const uint32 _h);
	virtual void ClearBuffer();

private:
	virtual void InitContext(const rhi::ContextSettings& _settings);
	virtual void InitViewPort(const math::Vec2i& _viewportSize);

public:
	void operator=(const GLRenderer&) = delete;
	void operator=(GLRenderer&&)		= delete;
};

} // namespace gl
} // namespace gfx
} // namespace pad