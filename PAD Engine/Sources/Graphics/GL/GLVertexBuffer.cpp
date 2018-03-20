#include <GL/glew.h>
#include <Graphics/GL/GLVertexBuffer.h>

namespace pad {
namespace gfx {
namespace gl  {

GLVertexBuffer::GLVertexBuffer()
{

}

GLVertexBuffer::~GLVertexBuffer()
{

}

void GLVertexBuffer::GenerateID()
{
	glGenBuffers(1, &m_id);
}

void GLVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void GLVertexBuffer::BindData(float* const _data, const uint32 _dataSize, const int32 _vertexElementCount, const uint8 _location)
{
	if (_data)
	{
		if (!m_id)
			GenerateID();

		Bind();

		glEnableVertexAttribArray(_location);
		glVertexAttribPointer(_location, _vertexElementCount, GL_FLOAT, GL_FALSE, 0, nullptr);
		glBufferData(GL_ARRAY_BUFFER,
			_dataSize * sizeof(*_data),
			_data,
			GL_STATIC_DRAW);
	}
}

} // namespace gl
} // namespace gfx
} // namespace pad