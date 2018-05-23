#pragma once
#include <Graphics/RHI/AUniformBufferObject.h>
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
	~GLRenderer();

	GLRenderer(const GLRenderer&)											= delete;
	GLRenderer(GLRenderer&&)												= delete;

private:
	std::unordered_map<std::string, rhi::AUniformBufferObject*> m_uniformBufferObjects;

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
		const rhi::RenderSettings _settings)								override;
	void SetCameraUniformBufferData(
		const math::Vec3f& _position,
		const math::Vec3f& _direction,
		const math::Mat4& _vp)												override;
	void SetLightsUniformBufferData(
		math::Vec4f* const _positions,
		math::Vec4f* const _directions,
		const uint8 _count)													override;
	void SetJointsUniformBufferData(
		float* const _joints,
		const uint8 _count)													override;
	void CreateUniformBuffer(const rhi::UniformBufferSettings& _settings)	override;
	bool LoadShaders(
		const std::string& _vPath, 
		const std::string& _fPath,
		const std::string& _name)											override;

private:
	void InitContext(const rhi::ContextSettings& _settings)					override;
	void InitViewPort(const math::Vec2i& _viewportSize)						override;

	void InitShaders();
	void InitMainBuffer(const rhi::ContextSettings& _settings);
	void InitCullFace(const rhi::ContextSettings& _settings);
	void InitDepthBuffer(const rhi::ContextSettings& _settings);
	void InitBlendFunction();
	void InitWindingOrder(const rhi::ContextSettings& _settings);
	void InitDefaultUniformBuffers();
	void SetCustomUniforms(rhi::shad::AShaderProgram* const _program, const rhi::RenderSettings& _settings);
	void SetUniformBufferData(const std::string& _bufferName, const void* const _data, const int _dataSize, const int _offset);
	void BindBufferToBindingPoint(const rhi::UniformBufferSettings& _settings);

	rhi::AUniformBufferObject* const GetUniformBufferObject(const std::string& _name);

public:
	void operator=(const GLRenderer&)										= delete;
	void operator=(GLRenderer&&)											= delete;
};

} // namespace gl
} // namespace gfx
} // namespace pad