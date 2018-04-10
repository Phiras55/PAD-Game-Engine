#pragma once

#include <unordered_map>
#include <System/Resource/Resource.h>
#include <Core/IDPool.h>

namespace pad	{
namespace sys	{
namespace res	{

template<typename T>
class AResourceManager
{
public:
	virtual ~AResourceManager();

protected:
	std::unordered_map<std::string, int>	m_resourceCollection;
	std::vector<T>							m_resourceArray;
								
	core::IDPool							m_idPool;
	int										m_lastResourceIndex;

public:
	void AddResource(const std::string _name, T const _resource);
	void RemoveResources(const std::vector<std::string>& _toRemove);

	virtual T* const GetResource(const std::string _name);
};

} // namespace res
} // namespace sys
} // namespace pad

#include <System/Resource/AResourceManager_impl.h>