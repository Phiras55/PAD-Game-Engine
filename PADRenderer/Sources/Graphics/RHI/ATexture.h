#pragma once
#include <Graphics/RHI/TextureParameters.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

class ATexture
{
public:
	virtual ~ATexture() = default;

protected:
	uint32 m_id;

public:
	virtual void GenerateID()															= 0;
	virtual void Bind()																	= 0;
	virtual void GenerateTexture(
		const int32 _w, 
		const int32 _h, 
		uchar* const _data, 
		const TextureParameters& _param)												= 0;

public:
	inline const uint32& GetID() const	{ return m_id; }
	inline uint32&		 GetID()		{ return m_id; }
};

} // namespace rhi
} // namespace gfx
} // namespace pad