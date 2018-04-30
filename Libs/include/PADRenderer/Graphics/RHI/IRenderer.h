#pragma once
#include <Common.h>
#include <Graphics/RHI/AVertexArray.h>
#include <Graphics/RHI/AVertexBuffer.h>
#include <Graphics/RHI/ContextSettings.h>
#include <Graphics/Model/MeshData.h>
#include <Graphics/RHI/RenderSettings.h>
#include <Graphics/RHI/ATexture.h>
#include <Graphics/RHI/UniformBufferSettings.h>

namespace pad {
namespace gfx {
namespace rhi { 

class IRenderer
{
public:
	virtual ~IRenderer() = default;

protected:
	std::vector<uint32> m_buffers;
	math::Vec2i			m_viewportSize;

public:
	virtual void Init(const ContextSettings& _settings)							= 0;
	virtual void ClearBuffer()													= 0;
	virtual void ResizeViewport(const uint32 _w, const uint32 _h)				= 0;
	virtual void GenerateTexture(
		ATexture* const _t, 
		const std::string& _path, 
		const rhi::TextureParameters& _param)									= 0;
	virtual void GenerateMesh(
		const mod::MeshData& _md, 
		rhi::AVertexArray* _vao, 
		rhi::AVertexBuffer* _ibo)												= 0;
	virtual void ForwardRendering(
		rhi::AVertexArray* const _vaos, 
		rhi::AVertexBuffer* const _ibos, 
		const rhi::RenderSettings _settings, 
		const math::Mat4& _vp)													= 0;
	virtual void SetCameraUniformBufferData(
		const math::Vec3f& _position,
		const math::Vec3f& _direction,
		const math::Mat4& _vp)													= 0;
	virtual void SetLightsUniformBufferData(
		math::Vec4f* const _positions, 
		math::Vec4f* const _directions)											= 0;
	virtual void CreateUniformBuffer(const UniformBufferSettings& _settings)	= 0;

protected:
	virtual void InitContext(const rhi::ContextSettings& _settings)				= 0;
	virtual void InitViewPort(const math::Vec2i& _viewportSize)					= 0;
};

} // namespace rhi
} // namespace gfx
} // namespace pad