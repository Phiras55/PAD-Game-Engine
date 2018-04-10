#pragma once
#include <Common.h>

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
	virtual void GenerateID()						= 0;
	virtual void Bind()								= 0;
	virtual void SetTextureParameters()				= 0;
	virtual void BindTexture(uchar* const _data)	= 0;

public:
	inline const uint32& GetID() const	{ return m_id; }
	inline uint32&		 GetID()		{ return m_id; }
};

} // namespace rhi
} // namespace gfx
} // namespace pad