#include <PCH.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/GL/GLVertexArray.h>
#include <Graphics/GL/GLVertexElementBuffer.h>

namespace pad {
namespace gfx {
namespace mod {

	Mesh::Mesh()// :
		//m_vao(new gl::GLVertexArray()),
		//m_ibo(new gl::GLVertexElementBuffer())
	{
	}

	Mesh::Mesh(const Mesh& _m)
	{
		m_vao = _m.m_vao;
		m_ibo = _m.m_ibo;
	}

	Mesh::~Mesh()
	{
		Clean();
	}

	void Mesh::Clean()
	{
		if (m_vao)
		{
			delete m_vao;
			m_vao = nullptr;
		}

		if (m_ibo)
		{
			delete m_ibo;
			m_ibo = nullptr;
		}
	}

	void Mesh::operator=(const Mesh& _other)
	{
		m_vao = _other.m_vao;
		m_ibo = _other.m_ibo;
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