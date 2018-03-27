#pragma once

namespace pad	{
namespace sys	{

class IModule
{
public:
	virtual void StartModule() = 0;
	virtual void StopModule() = 0;
};

} // namespace sys
} // namespace pad