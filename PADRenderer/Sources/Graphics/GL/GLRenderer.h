#pragma once
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

private:
	std::unordered_map<std::string, int32>	m_bindingPoints;

public:
	void Init(const rhi::ContextSettings& _settings)						override;
	void ResizeViewport(const uint32 _w, const uint32 _h)					override;
	void ClearBuffer()														override;
	void GenerateMesh(const mod::MeshData& _md, rhi::AVertexArray* _vao, rhi::AVertexBuffer* _ibo) override;
	void GenerateTexture(
		rhi::ATexture* const _t,
		const std::string& _path,
		const rhi::TextureParameters& _param)								override;
	void ForwardRendering(
		rhi::AVertexArray* const _vaos,
		rhi::AVertexBuffer* const _ibos,
		const rhi::RenderSettings _settings,
		const math::Mat4& _vp)												override;
	void CreateUniformBuffer(const rhi::UniformBufferSettings& _settings)	override;
	int32 GetBindingPoint(const std::string& _bindingBlockName)				override;

private:
	void InitContext(const rhi::ContextSettings& _settings)					override;
	void InitViewPort(const math::Vec2i& _viewportSize)						override;

	void InitMainBuffer(const rhi::ContextSettings& _settings);
	void InitCullFace(const rhi::ContextSettings& _settings);
	void InitDepthBuffer(const rhi::ContextSettings& _settings);
	void InitWindingOrder(const rhi::ContextSettings& _settings);
	void SetCustomUniforms(rhi::shad::AShaderProgram* const _program, const rhi::RenderSettings& _settings);
	void UniformBufferTesting(rhi::shad::AShaderProgram* const _program, const rhi::RenderSettings& _settings);

public:
	void operator=(const GLRenderer&)										= delete;
	void operator=(GLRenderer&&)											= delete;
};

} // namespace gl
} // namespace gfx
} // namespace pad