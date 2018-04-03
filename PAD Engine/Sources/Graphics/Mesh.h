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
	inline uint32&		GetVAO()				{ return m_vao; }
	inline const uint32 GetVAO() const			{ return m_vao; }
	inline uint32&		GetIndiceCount()		{ return m_indiceCount; }
	inline const uint32 GetIndiceCount() const	{ return m_indiceCount; }

	inline void SetIndiceCount(const uint32 _count) { m_indiceCount = _count; }

public:
	void operator=(const Mesh&) = delete;
	void operator=(Mesh&&)		= delete;
};

} // namespace gfx
} // namespace pad