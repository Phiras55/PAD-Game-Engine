#include <Graphics/GL/GLTexture.h>
#include <Utilities/EnumUtils.h>

#include <GL/glew.h>

namespace pad	{
namespace gfx	{
namespace gl	{

GLTexture::GLTexture()
{
	m_id = GL_INVALID_VALUE;
}

void GLTexture::GenerateID()
{
	glGenTextures(1, &m_id);
}

void GLTexture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void GLTexture::SetTextureParameters(const rhi::TextureParameters& _param)
{
	CheckWrapParameters(_param.sWrap, rhi::AxisType::S);
	CheckWrapParameters(_param.tWrap, rhi::AxisType::T);
	CheckFilteringParameters(_param.minFiltering, rhi::AxisType::S);
	CheckFilteringParameters(_param.magFiltering, rhi::AxisType::T);
	CheckMipmapParameters(_param.minMipmap, rhi::AxisType::S);
	CheckMipmapParameters(_param.magMipmap, rhi::AxisType::T);
}

void GLTexture::CheckWrapParameters(const rhi::WrapType& _param, const rhi::AxisType& _axis)
{
	int wrap = 0;
	switch (_param)
	{
	case rhi::E_WRAP_TYPE::CLAMP_BORDER:
		wrap = GL_CLAMP_TO_BORDER;
		break;
	case rhi::E_WRAP_TYPE::CLAMP_EDGE:
		wrap = GL_CLAMP_TO_EDGE;
		break;
	case rhi::E_WRAP_TYPE::MIRRORED_REPEAT:
		wrap = GL_MIRRORED_REPEAT;
		break;
	case rhi::E_WRAP_TYPE::REPEAT:
		wrap = GL_REPEAT;
		break;
	}
	glTexParameteri(GL_TEXTURE_2D, (_axis == rhi::E_AXIS_TYPE::S ? GL_TEXTURE_WRAP_S : GL_TEXTURE_WRAP_T), wrap);
}

void GLTexture::CheckFilteringParameters(const rhi::TextureFiltering& _param, const rhi::AxisType& _axis)
{
	int filtering = 0;
	switch (_param)
	{
	case rhi::E_TEXTURE_FILTERING::LINEAR:
		filtering = GL_NEAREST;
		break;
	case rhi::E_TEXTURE_FILTERING::NEAREST:
		filtering = GL_LINEAR;
		break;
	}
	glTexParameteri(GL_TEXTURE_2D, (_axis == rhi::E_AXIS_TYPE::S ? GL_TEXTURE_MIN_FILTER : GL_TEXTURE_MAG_FILTER), filtering);
}

void GLTexture::CheckMipmapParameters(const rhi::MipmapType& _param, const rhi::AxisType& _axis)
{
	int mipmap = 0;
	switch (_param)
	{
	case rhi::E_MIPMAP_TYPE::LINEAR_LINEAR:
		mipmap = GL_LINEAR_MIPMAP_LINEAR;
		break;
	case rhi::E_MIPMAP_TYPE::LINEAR_NEAREST:
		mipmap = GL_LINEAR_MIPMAP_NEAREST;
		break;
	case rhi::E_MIPMAP_TYPE::NEAREST_LINEAR:
		mipmap = GL_NEAREST_MIPMAP_LINEAR;
		break;
	case rhi::E_MIPMAP_TYPE::NEAREST_NEAREST:
		mipmap = GL_NEAREST_MIPMAP_NEAREST;
		break;
	}
	glTexParameteri(GL_TEXTURE_2D, (_axis == rhi::E_AXIS_TYPE::S ? GL_TEXTURE_MIN_FILTER : GL_TEXTURE_MAG_FILTER), mipmap);
}

void GLTexture::GenerateTexture(const int32 _w, const int32 _h, uchar* const _data)
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _w, _h, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

} // namespace gl
} // namespace gfx
} // namespace pad