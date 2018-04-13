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
		sWrap(E_WRAP_TYPE::REPEAT),
		tWrap(E_WRAP_TYPE::REPEAT),
		minFiltering(E_TEXTURE_FILTERING::LINEAR),
		magFiltering(E_TEXTURE_FILTERING::LINEAR),
		minMipmap(E_MIPMAP_TYPE::LINEAR_LINEAR),
		magMipmap(E_MIPMAP_TYPE::LINEAR_LINEAR)
	{
	}

	WrapType			sWrap;
	WrapType			tWrap;
	TextureFiltering	minFiltering;
	TextureFiltering	magFiltering;
	MipmapType			minMipmap;
	MipmapType			magMipmap;
};

// S = Minifying
// T = Magnifying
enum class E_AXIS_TYPE : uint8
{
	S,
	T
};

using AxisType = E_AXIS_TYPE;

}
}
}