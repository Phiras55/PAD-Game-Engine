#pragma once
#include <iostream>
#include <map>

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
	~GLRenderer()															= default;

	GLRenderer(const GLRenderer&)											= delete;
	GLRenderer(GLRenderer&&)												= delete;

public:
	void StartModule()														override;
	void StopModule()														override;

	void Init(const rhi::ContextSettings& _settings)						override;
	void Draw(const mod::Mesh& _mesh, const rhi::RenderSettings& _settings, math::Mat4& _vp) override;
	void ResizeViewport(const uint32 _w, const uint32 _h)					override;
	void GenerateMesh(mod::Mesh& _m, const mod::MeshData& _md)				override;
	void ClearBuffer()														override;

private:
	void InitContext(const rhi::ContextSettings& _settings)					override;
	void InitViewPort(const math::Vec2i& _viewportSize)						override;

	void InitMainBuffer(const rhi::ContextSettings& _settings);
	void InitCullFace(const rhi::ContextSettings& _settings);
	void GenerateBuffer(uint32& _id);

public:
	void operator=(const GLRenderer&)										= delete;
	void operator=(GLRenderer&&)											= delete;
};

} // namespace gl
} // namespace gfx
} // namespace pad