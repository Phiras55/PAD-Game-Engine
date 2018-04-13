#pragma once
#include <Graphics/RHI/AVertexArray.h>
#include <Graphics/RHI/AVertexBuffer.h>

namespace pad	{
namespace gfx	{
namespace mod	{

class Mesh
{
public:
	Mesh();
	~Mesh();

	Mesh(const Mesh& _m);

private:
	rhi::AVertexArray*  m_vao;
	rhi::AVertexBuffer* m_ibo;

public:
	void Clean();

	rhi::AVertexArray*					GetVAO();
	rhi::AVertexBuffer*					GetIBO();
	rhi::AVertexArray* const			GetVAO() const;
	rhi::AVertexBuffer* const			GetIBO() const;
	inline uint32&						GetVertexArrayID()			{ return m_vao->GetID(); }
	inline const uint32					GetVertexArrayID() const	{ return m_vao->GetID(); }
	inline uint32&						GetIndiceCount()			{ return m_ibo->GetCount(); }
	inline const uint32					GetIndiceCount() const		{ return m_ibo->GetCount(); }

	inline void SetIndiceCount(const uint32 _count) { m_ibo->SetCount(_count); }
	inline void SetVertexElementBuffer(rhi::AVertexBuffer* const _ibo) { m_ibo = _ibo; }
	inline void SetVertexArray(rhi::AVertexArray* const _vao) { m_vao = _vao; }

public:
	void operator=(const Mesh& _other);
};

} // namespace mod
} // namespace gfx
} // namespace pad