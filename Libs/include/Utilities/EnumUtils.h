#pragma once
namespace pad	{
namespace util	{

template <typename T>
bool IsFlagSet(const T& _flags, const T& _flag)
{
	return (int)operator&(_flags, _flag) != 0;
}

} // namespace util
} // namespace pad