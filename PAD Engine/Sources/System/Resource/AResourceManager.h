#pragma once

#include <unordered_map>
#include <System/Resource/Resource.h>
#include <Core/IDPool.h>

namespace pad	{
namespace sys	{
namespace res	{

class AResourceManager
{
public:
	AResourceManager();
	~AResourceManager();

private:
	std::unordered_map<std::string, int>	resourceCollection;
	std::vector<Resource>					resourceArray;

protected:
	core::IDPool							idPool;
	int										lastResourceIndex;

public:
	void AddResource(std::string _name, Resource _resource);
	void RemoveResources(const std::vector<std::string>& _toRemove);
};

} // namespace res
} // namespace sys
} // namespace pad