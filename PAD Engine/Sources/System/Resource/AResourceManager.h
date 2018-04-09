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
	virtual ~AResourceManager();

protected:
	std::unordered_map<std::string, int>	m_resourceCollection;
	std::vector<Resource*>					m_resourceArray;
								
	core::IDPool							m_idPool;
	int										m_lastResourceIndex;

public:
	void AddResource(const std::string _name, Resource* const _resource);
	void RemoveResources(const std::vector<std::string>& _toRemove);

	virtual Resource* const GetResource(const std::string _name) = 0;
};

} // namespace res
} // namespace sys
} // namespace pad