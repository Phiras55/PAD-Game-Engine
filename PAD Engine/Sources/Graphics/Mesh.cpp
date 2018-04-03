#include <GL/glew.h>

#include <Graphics/Mesh.h>

namespace pad {
namespace gfx {

	Mesh::Mesh() :
		m_vao(0), 
		m_indiceCount(0)
	{

	}

	Mesh::~Mesh()
	{

	}

} // namespace gfx
} // namespace pad