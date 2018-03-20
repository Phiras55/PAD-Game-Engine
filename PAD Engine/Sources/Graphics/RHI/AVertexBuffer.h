#pragma once
#include <Common.h>

#include <Graphics/RHI/AVertexArray.h>

namespace pad {
namespace gfx {
namespace rhi {

class AVertexBuffer : public rhi::AVertexArray
{
protected:
	uint32 m_count;

public:
	virtual void BindData(uint32* const _data, const uint32 _dataSize) = 0;
	virtual void BindData(float* const _data, const uint32 _dataSize, const int32 _vertexElementCount, const uint8 _location) = 0;

public:
	inline 			uint32& GetCount()			{ return m_count; }
	inline const	uint32	GetCount() const	{ return m_count; }

	inline void SetCount(const uint32 _count)	{ m_count = _count; }
};

} // namespace rhi
} // namespace gfx
} // namespace pad