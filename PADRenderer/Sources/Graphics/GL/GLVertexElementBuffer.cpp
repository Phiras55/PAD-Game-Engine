#include <PCH.h>
#include <Graphics/GL/GLVertexElementBuffer.h>

namespace pad {
namespace gfx {
namespace gl  {

GLVertexElementBuffer::GLVertexElementBuffer()
{
	m_id	= GL_INVALID_VALUE;
	m_count = 0;
}

void GLVertexElementBuffer::GenerateID()
{
	glGenBuffers(1, &m_id);
}

void GLVertexElementBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void GLVertexElementBuffer::BindData(uint32* const _data, const uint32 _dataSize)
{
	if (_data)
	{
		if (!m_id)
			GenerateID();

		Bind();

		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			_dataSize * sizeof(*_data),
			_data, GL_STATIC_DRAW);

		m_count = _dataSize;
	}
}

} // namespace gl
} // namespace gfx
} // namespace pad