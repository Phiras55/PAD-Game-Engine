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

	void Mesh::LoadGeometry(const MeshData& data)
	{
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		BindBuffer(data.positions, data.positionCount, 3, E_VERTEX_ATTRIB_LOCATION::POSITION);
		BindBuffer(data.uvs, data.uvCount, 2, E_VERTEX_ATTRIB_LOCATION::UV);
		BindBuffer(data.normals, data.normalCount, 3, E_VERTEX_ATTRIB_LOCATION::NORMAL);

		if (data.indices)
		{
			uint32 buffer;
			glGenBuffers(1, &buffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
			m_indiceCount = data.indiceCount;
		}
	}

	void Mesh::BindBuffer(float* const _data, const uint32 _dataSize, const int32 _vertexElementCount, const E_VERTEX_ATTRIB_LOCATION _location)
	{
		if (_data)
		{
			uint32 buffer;
			uint32 location = static_cast<uint32>(_location);

			glGenBuffers(1, &buffer);
			glBindBuffer(GL_ARRAY_BUFFER, buffer);
			glEnableVertexAttribArray(location);
			glVertexAttribPointer(location, _vertexElementCount, GL_FLOAT, GL_FALSE, 0, nullptr);
			glBufferData(GL_ARRAY_BUFFER,
				_dataSize * sizeof(*_data),
				_data,
				GL_STATIC_DRAW);
		}
	}

} // namespace gfx
} // namespace pad