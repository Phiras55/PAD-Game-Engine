#pragma once
#include <System/ECS/AComponent.h>
namespace pad	{
namespace sys	{
namespace res	{

class IComponentPool 
{
public:
	virtual ~IComponentPool() = default;

public:
	virtual void				DeleteComponent(ecs::AComponent* const _comp) = 0;
};

} // namespace res
} // namespace sys
} // namespace pad