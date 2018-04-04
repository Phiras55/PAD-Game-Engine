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
	std::unordered_map<std::string, int>	m_resourceCollection;
	std::vector<Resource>					m_resourceArray;
											
protected:									
	core::IDPool							m_idPool;
	int										m_lastResourceIndex;

public:
	void AddResource(std::string _name, Resource _resource);
	void RemoveResources(const std::vector<std::string>& _toRemove);
};

} // namespace res
} // namespace sys
} // namespace pad