#pragma once
#include <cstdint>
#include <type_traits>

namespace sl
{

enum class E_CHANNEL_TYPE : uint8_t
{
	NONE	= 0x00,
	INFO	= 0x01,
	TRACE	= 0x02,
	WARNING = 0x04,
	ERROR	= 0x08,
	FATAL	= 0x10,
	ALL = INFO | TRACE | WARNING | ERROR | FATAL
};

using enumType = std::underlying_type_t<E_CHANNEL_TYPE>;

E_CHANNEL_TYPE operator|(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right);
E_CHANNEL_TYPE& operator|=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right);

E_CHANNEL_TYPE operator&(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right);
E_CHANNEL_TYPE& operator&=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right);

}