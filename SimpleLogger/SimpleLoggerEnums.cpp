#include <SimpleLoggerEnums.h>

namespace sl
{

E_CHANNEL_TYPE operator|(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right)
{
	return (E_CHANNEL_TYPE)(static_cast<enumType>(left) | static_cast<enumType>(right));
}

E_CHANNEL_TYPE& operator|=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right)
{
	left = (E_CHANNEL_TYPE)(static_cast<enumType>(left) | static_cast<enumType>(right));
	return left;
}

E_CHANNEL_TYPE operator&(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right)
{
	return (E_CHANNEL_TYPE)(static_cast<enumType>(left) & static_cast<enumType>(right));
}

E_CHANNEL_TYPE& operator&=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right)
{
	left = (E_CHANNEL_TYPE)(static_cast<enumType>(left) & static_cast<enumType>(right));
	return left;
}

}