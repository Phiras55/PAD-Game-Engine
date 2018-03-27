#include <System/Resource/AResourceManager.h>

namespace pad	{
namespace sys	{
namespace res	{

AResourceManager::AResourceManager() :
	lastResourceIndex(-1)
{

}

AResourceManager::~AResourceManager()
{

}

void AResourceManager::AddResource(std::string _name, Resource _resource)
{
	if (resourceCollection.count(_name))
		return;

	int resourceIndex = idPool.GenerateID();

	if (resourceIndex == resourceArray.size() - 1)
		resourceArray.push_back(_resource);
	else
		resourceArray[resourceIndex] = _resource;

	++lastResourceIndex;
}

void AResourceManager::RemoveResources(const std::vector<std::string>& _toRemove)
{
	for (int i = 0; i < _toRemove.size(); ++i)
	{
		for (auto pair : resourceCollection)
		{
			if (pair.second == lastResourceIndex - 1)
				pair.second = resourceCollection[_toRemove[i]];
		}

		std::swap(resourceArray[resourceCollection[_toRemove[i]]], resourceArray[lastResourceIndex - 1]);

		resourceCollection.erase(_toRemove[i]);

		--lastResourceIndex;
	}
}

} // namespace res
} // namespace sys
} // namespace pad