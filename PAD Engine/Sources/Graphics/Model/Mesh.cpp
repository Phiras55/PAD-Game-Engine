#include <Graphics/Model/Mesh.h>
#include <Graphics/GL/GLVertexArray.h>
#include <Graphics/GL/GLVertexElementBuffer.h>

namespace pad {
namespace gfx {
namespace mod {

	Mesh::Mesh() :
		m_vao(nullptr),
		m_ibo(nullptr)
	{
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

} // namespace mod
} // namespace gfx
} // namespace pad