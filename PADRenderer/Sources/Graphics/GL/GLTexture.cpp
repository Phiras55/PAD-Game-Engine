#include <Graphics/GL/GLTexture.h>

#include <GL/glew.h>

namespace pad	{
namespace gfx	{
namespace gl	{

void GLTexture::GenerateID()
{
	glGenTextures(1, &m_id);
}

void GLTexture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

} // namespace gl
} // namespace gfx
} // namespace pad