#pragma once
#include <Common.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

enum class E_WRAP_TYPE : uint8
{
	REPEAT,
	MIRRORED_REPEAT,
	CLAMP_EDGE,
	CLAMP_BORDER
};

enum class E_TEXTURE_FILTERING : uint8
{
	NEAREST,
	LINEAR
};

enum class E_MIPMAP_TYPE : uint8
{
	NEAREST_NEAREST,
	NEAREST_LINEAR,
	LINEAR_NEAREST,
	LINEAR_LINEAR
};

using WrapType			= E_WRAP_TYPE;
using TextureFiltering	= E_TEXTURE_FILTERING;
using MipmapType		= E_MIPMAP_TYPE;

struct TextureParameters
{
	TextureParameters() :
		wrap(E_WRAP_TYPE::REPEAT),
		filtering(E_TEXTURE_FILTERING::LINEAR),
		mipmap(E_MIPMAP_TYPE::LINEAR_LINEAR)
	{
	}

	WrapType			wrap;
	TextureFiltering	filtering;
	MipmapType			mipmap;
};

}
}
}