#pragma once
#include <Graphics/RHI/ContextSettings.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/Model/MeshData.h>
#include <System/IModule.h>

#include <Common.h>

namespace pad {
namespace gfx {
namespace rhi { 

class IRenderer : public sys::IModule
{
public:
	virtual void Init(const ContextSettings& _settings)						= 0;
	virtual void Draw(const mod::Mesh& _m, const RenderSettings& _settings)	= 0;
	virtual void ClearBuffer()												= 0;
	virtual void ResizeViewport(const uint32 _w, const uint32 _h)			= 0;

protected:
	virtual void InitContext(const math::Vec4f& _clearColor)	= 0;
	virtual void InitViewPort(const math::Vec2i& _viewportSize)	= 0;
};

} // namespace rhi
} // namespace gfx
} // namespace pad