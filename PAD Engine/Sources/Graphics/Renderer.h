#pragma once
#include <iostream>

#include <Graphics/RenderSettings.h>
#include <Graphics/Mesh.h>
#include <System/IModule.h>

namespace pad	{
namespace gfx	{

class Renderer final : public sys::IModule
{
public:
	Renderer();
	virtual ~Renderer() = default;

	Renderer(const Renderer&)	= delete;
	Renderer(Renderer&&)		= delete;

public:
	virtual void StartModule();
	virtual void StopModule();

	void Init(const RenderSettings& _settings);
	void Draw(const Mesh& _mesh);
	void ClearBuffer();

	static void LoadGeometry(Mesh& mesh, const MeshData& data);

private:
	void InitContext(const math::Vec4f& _clearColor);
	void InitViewPort(const math::Vec2i& _viewportSize);
	static void BindBuffer(float* const _data, const uint32 _dataSize, const int32 _vertexElementCount, const E_VERTEX_ATTRIB_LOCATION _location);

public:
	void operator=(const Renderer&) = delete;
	void operator=(Renderer&&)		= delete;
};

} // namespace gfx
} // namespace pad