#include <SimpleLoggerEnums.h>

namespace sl
{

E_CHANNEL_TYPE operator|(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right)
{
	return (E_CHANNEL_TYPE)(static_cast<TypeChanType>(left) | static_cast<TypeChanType>(right));
}

E_CHANNEL_TYPE& operator|=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right)
{
	left = (E_CHANNEL_TYPE)(static_cast<TypeChanType>(left) | static_cast<TypeChanType>(right));
	return left;
}

E_CHANNEL_TYPE operator&(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right)
{
	return (E_CHANNEL_TYPE)(static_cast<TypeChanType>(left) & static_cast<TypeChanType>(right));
}

E_CHANNEL_TYPE& operator&=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right)
{
	left = (E_CHANNEL_TYPE)(static_cast<TypeChanType>(left) & static_cast<TypeChanType>(right));
	return left;
}

E_CHANNEL_OUTPUT operator|(const E_CHANNEL_OUTPUT left, const E_CHANNEL_OUTPUT right)
{
	return (E_CHANNEL_OUTPUT)(static_cast<TypeChanOutput>(left) | static_cast<TypeChanOutput>(right));
}

E_CHANNEL_TYPE& operator|=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right)
{
	left = (E_CHANNEL_TYPE)(static_cast<TypeChanOutput>(left) | static_cast<TypeChanOutput>(right));
	return left;
}

E_CHANNEL_TYPE operator&(const E_CHANNEL_TYPE left, const E_CHANNEL_TYPE right)
{
	return (E_CHANNEL_TYPE)(static_cast<TypeChanOutput>(left) & static_cast<TypeChanOutput>(right));
}

E_CHANNEL_TYPE& operator&=(E_CHANNEL_TYPE& left, const E_CHANNEL_TYPE right)
{
	left = (E_CHANNEL_TYPE)(static_cast<TypeChanOutput>(left) & static_cast<TypeChanOutput>(right));
	return left;
}

}