#pragma once

#include <string>

namespace pad	{
namespace sys	{
namespace res	{

class Resource
{
public:
	Resource();
	~Resource();

private:
	std::string m_name;

public:
	const	std::string&	GetName() const						{ return m_name; }
			void			SetName(const std::string _name)	{ m_name = _name; }
};

} // namespace res
} // namespace sys
} // namespace pad