#pragma once
#include <Common.h>
#include <Graphics/RHI/AVertexArray.h>
#include <Graphics/RHI/TextureParameters.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

class ATexture : public AVertexArray
{
public:
	virtual ~ATexture() = default;

public:
	virtual void GenerateTexture(
		const int32 _w, 
		const int32 _h, 
		uchar* const _data, 
		const TextureParameters& _param) = 0;
};

} // namespace rhi
} // namespace gfx
} // namespace pad