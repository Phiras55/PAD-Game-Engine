#pragma once
#include <Graphics/RHI/AVertexArray.h>
#include <Graphics/RHI/AVertexBuffer.h>
#include <System/Resource/Resource.h>

namespace pad	{
namespace gfx	{
namespace mod	{

class Mesh : public sys::res::Resource
{
public:
	Mesh();
	~Mesh();

	Mesh(const Mesh&)	= delete;
	Mesh(Mesh&&)		= delete;

private:
	rhi::AVertexArray*  m_vao;
	rhi::AVertexBuffer* m_ibo;

public:
	inline uint32&		GetVertexArrayID()			{ return m_vao->GetID(); }
	inline const uint32 GetVertexArrayID() const	{ return m_vao->GetID(); }
	inline uint32&		GetIndiceCount()			{ return m_ibo->GetCount(); }
	inline const uint32 GetIndiceCount() const		{ return m_ibo->GetCount(); }

	inline void SetIndiceCount(const uint32 _count) { m_ibo->SetCount(_count); }

public:
	void operator=(const Mesh&) = delete;
	void operator=(Mesh&&)		= delete;
};

} // namespace mod
} // namespace gfx
} // namespace pad