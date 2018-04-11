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
	void Init(const rhi::ContextSettings& _settings)						override;
	void ResizeViewport(const uint32 _w, const uint32 _h)					override;
	void GenerateTexture(uint32& _textureID, const std::string& _path)		override;
	void ClearBuffer()														override;
	void GenerateMesh(const mod::MeshData& _md, rhi::AVertexArray* _vao, rhi::AVertexBuffer* _ibo) override;
	void ForwardRendering(
		rhi::AVertexArray* const * const _vaos, 
		rhi::AVertexBuffer* const * const _ibos, 
		const rhi::RenderSettings* const _settings, 
		const math::Mat4& _vp, 
		const uint32 _meshCount) override;

private:
	void InitContext(const rhi::ContextSettings& _settings)					override;
	void InitViewPort(const math::Vec2i& _viewportSize)						override;

	void InitMainBuffer(const rhi::ContextSettings& _settings);
	void InitCullFace(const rhi::ContextSettings& _settings);
	void GenerateBuffer(uint32& _id);
	void SetCustomUniforms(rhi::shad::AShaderProgram* const _program, const rhi::RenderSettings& _settings);

public:
	void operator=(const GLRenderer&)										= delete;
	void operator=(GLRenderer&&)											= delete;
};

} // namespace gl
} // namespace gfx
} // namespace pad