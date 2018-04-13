#pragma once
#include <Graphics/RHI/AVertexArray.h>
#include <Graphics/RHI/AVertexBuffer.h>
#include <Graphics/RHI/ContextSettings.h>
#include <Graphics/Model/MeshData.h>
#include <Graphics/RHI/RenderSettings.h>

#include <Common.h>
#include <vector>

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
	virtual void GenerateTexture(uint32& _textureID, const std::string& _path)	= 0;
	virtual void GenerateMesh(
		const mod::MeshData& _md, 
		rhi::AVertexArray* _vao, 
		rhi::AVertexBuffer* _ibo)												= 0;
	virtual void ForwardRendering(
		rhi::AVertexArray* const _vaos, 
		rhi::AVertexBuffer* const _ibos, 
		const rhi::RenderSettings _settings, 
		const math::Mat4& _vp)													= 0;

protected:
	virtual void InitContext(const rhi::ContextSettings& _settings)				= 0;
	virtual void InitViewPort(const math::Vec2i& _viewportSize)					= 0;
};

} // namespace rhi
} // namespace gfx
} // namespace pad