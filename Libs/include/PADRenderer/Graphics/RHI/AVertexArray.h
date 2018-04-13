#pragma once
#include <Common.h>

namespace pad {
namespace gfx {
namespace rhi {

class AVertexArray
{
public:
	~AVertexArray() = default;

protected:
	uint32 m_id;

public:
	virtual void GenerateID()	= 0;
	virtual void Bind()			= 0;

public:
	inline virtual uint32&		GetID()			{ return m_id; }
	inline virtual const uint32 GetID() const	{ return m_id; }
};

} // namespace rhi
} // namespace gfx
} // namespace pad