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

	Mesh::~Mesh()
	{
		if (m_vao)
			delete m_vao;

		if (m_ibo)
			delete m_ibo;
	}

} // namespace mod
} // namespace gfx
} // namespace pad