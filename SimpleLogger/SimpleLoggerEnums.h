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

using TypeChanType	= std::underlying_type_t<E_CHANNEL_TYPE>;
using ChanType		= E_CHANNEL_TYPE;

E_CHANNEL_TYPE operator|(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right);
E_CHANNEL_TYPE& operator|=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right);

E_CHANNEL_TYPE operator&(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right);
E_CHANNEL_TYPE& operator&=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right);

enum class E_CHANNEL_OUTPUT : uint8_t
{
	NONE	= 0x00,
	CONSOLE = 0x01,
	FILE	= 0x02,
	ALL		= 0x04	
};

using TypeChanOutput	= std::underlying_type_t<E_CHANNEL_OUTPUT>;
using ChanOutput		= E_CHANNEL_OUTPUT;

E_CHANNEL_OUTPUT operator|(const E_CHANNEL_OUTPUT left, const E_CHANNEL_OUTPUT right);
E_CHANNEL_OUTPUT& operator|=(E_CHANNEL_OUTPUT& left, const E_CHANNEL_OUTPUT right);

E_CHANNEL_OUTPUT operator&(const E_CHANNEL_OUTPUT left, const E_CHANNEL_OUTPUT right);
E_CHANNEL_OUTPUT& operator&=(E_CHANNEL_OUTPUT& left, const E_CHANNEL_OUTPUT right);

}