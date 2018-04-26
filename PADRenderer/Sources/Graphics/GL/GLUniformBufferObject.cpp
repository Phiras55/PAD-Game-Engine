#include <GL/glew.h>

#include <Common.h>
#include <Graphics/GL/GLUniformBufferObject.h>

namespace pad	{
namespace gfx	{
namespace gl	{

GLUniformBufferObject::GLUniformBufferObject()
{
	m_id = INVALID_VALUE;
}

GLUniformBufferObject::~GLUniformBufferObject()
{

}

void GLUniformBufferObject::GenerateID()
{
	glGenBuffers(1, &m_id);
}

void GLUniformBufferObject::Bind()
{
	glBindBuffer(GL_UNIFORM_BUFFER, m_id);
}

void GLUniformBufferObject::Unbind()
{
	glBindBuffer(GL_UNIFORM_BUFFER, INVALID_VALUE);
}

void GLUniformBufferObject::InitializeBufferData(const int32 _dataSize)
{
	Bind();

	glBufferData(GL_UNIFORM_BUFFER, _dataSize, (void*)0, GL_DYNAMIC_DRAW);

	Unbind();
}

void GLUniformBufferObject::BindData(const int32 _size, const int32 _offset, void* const _data)
{
	Bind();

	glBufferSubData(GL_UNIFORM_BUFFER, _offset, _size, _data);

	Unbind();
}

}  // namespace gl
}  // namespace gfx
}  // namespace pad