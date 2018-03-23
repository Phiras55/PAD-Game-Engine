#include <Graphics/RHI/ContextSettings.h>

namespace pad	{
namespace gfx	{
namespace rhi	{

E_BUFFER_TYPE operator| (const E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right)
{
	return (BufferType)(static_cast<TypeBufferType>(left) | static_cast<TypeBufferType>(right));
}

E_BUFFER_TYPE& operator|=(E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right)
{
	left = (BufferType)(static_cast<TypeBufferType>(left) | static_cast<TypeBufferType>(right));
	return left;
}

E_BUFFER_TYPE  operator& (const E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right)
{
	return (BufferType)(static_cast<TypeBufferType>(left) & static_cast<TypeBufferType>(right));
}

E_BUFFER_TYPE& operator&=(E_BUFFER_TYPE& left, const E_BUFFER_TYPE& right)
{
	left = (BufferType)(static_cast<TypeBufferType>(left) & static_cast<TypeBufferType>(right));
	return left;
}

} // namespace rhi
} // namesapce gfx
} // namesapce pad