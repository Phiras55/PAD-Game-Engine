#pragma once
#include <Graphics/MeshData.h>
#include <Graphics/ShaderType.h>

namespace pad {
namespace gfx {

class Mesh
{
public:
	Mesh();
	~Mesh();

	Mesh(const Mesh&)	= delete;
	Mesh(Mesh&&)		= delete;

private:
	uint32 m_vao;
	uint32 m_indiceCount;

public:
	void LoadGeometry(const MeshData& data);

private:
	void BindBuffer(float* const _data, const uint32 _dataSize, const int32 _vertexElementCount, const E_VERTEX_ATTRIB_LOCATION _location);

public:
	void operator=(const Mesh&) = delete;
	void operator=(Mesh&&)		= delete;
};

} // namespace gfx
} // namespace pad