#pragma once
#include <System/Event/Subject.h>
#include <System/Event/EventArgs.h>

namespace pad	{
namespace sys	{
namespace evnt	{

class IObserver 
{
public:
	virtual void Update(Subject* const _sender, EventArgs* const _args) = 0;
};

}  // namespace evnt
}  // namespace sys
}  // namespace pad