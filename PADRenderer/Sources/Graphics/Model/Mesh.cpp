#include <PCH.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/GL/GLVertexArray.h>
#include <Graphics/GL/GLVertexElementBuffer.h>

namespace pad {
namespace gfx {
namespace mod {

	Mesh::Mesh() :
		m_vao(new gl::GLVertexArray()),
		m_ibo(new gl::GLVertexElementBuffer())
	{
	}

	Mesh::Mesh(const Mesh& _m) :
		Mesh()
	{
		*this = _m;
	}

	Mesh::~Mesh()
	{
		Clean();
	}

	void Mesh::Clean()
	{
		delete m_vao;
		delete m_ibo;
	}

	void Mesh::operator=(const Mesh& _other)
	{
		m_vao->SetID(_other.m_vao->GetID());
		m_ibo->SetID(_other.m_ibo->GetID());
		m_ibo->SetCount(_other.m_ibo->GetCount());
	}

	rhi::AVertexArray* const Mesh::GetVAO() const
	{
		return m_vao;
	}

	rhi::AVertexArray* Mesh::GetVAO()
	{
		return m_vao;
	}

	rhi::AVertexBuffer* const Mesh::GetIBO() const
	{
		return m_ibo;
	}

	rhi::AVertexBuffer* Mesh::GetIBO()
	{
		return m_ibo;
	}

} // namespace mod
} // namespace gfx
} // namespace pad