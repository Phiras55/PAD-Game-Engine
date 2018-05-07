#pragma once
#include <Common.h>
namespace pad {
namespace gfx {
namespace rhi {

class AVertexArray
{
public:
	virtual ~AVertexArray() = default;

protected:
	uint32 m_id;

public:
	virtual void GenerateID()	= 0;
	virtual void Bind()			= 0;
	virtual void Unbind()		= 0;

public:
	inline virtual uint32&		GetID()			{ return m_id; }
	inline virtual const uint32 GetID() const	{ return m_id; }
	
	inline virtual void SetID(const uint32 _id) { m_id = _id; }
};

} // namespace rhi
} // namespace gfx
} // namespace pad