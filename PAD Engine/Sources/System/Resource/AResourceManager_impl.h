#include <System/Resource/AResourceManager.h>

namespace pad	{
namespace sys	{
namespace res	{

template<typename T>
AResourceManager<T>::~AResourceManager()
{

}

template<typename T>
void AResourceManager<T>::AddResource(const std::string _name, T const _resource)
{
	if (m_resourceCollection.count(_name))
		return;

	int resourceIndex = m_idPool.GenerateID();

	if (resourceIndex == m_resourceArray.size())
		m_resourceArray.push_back(_resource);
	else
		m_resourceArray[resourceIndex] = _resource;

	m_resourceCollection[_name] = resourceIndex;

	++m_lastResourceIndex;
}

template<typename T>
void AResourceManager<T>::RemoveResources(const std::vector<std::string>& _toRemove)
{
	for (unsigned int i = 0; i < _toRemove.size(); ++i)
	{
		for (auto pair : m_resourceCollection)
		{
			if (pair.second == m_lastResourceIndex - 1)
				pair.second = m_resourceCollection[_toRemove[i]];
		}

		std::swap(m_resourceArray[m_resourceCollection[_toRemove[i]]], m_resourceArray[m_lastResourceIndex - 1]);

		m_resourceCollection.erase(_toRemove[i]);

		--m_lastResourceIndex;
	}
}

template<typename T>
T* const AResourceManager<T>::GetResource(const std::string _name)
{
	if (m_resourceCollection.find(_name) != m_resourceCollection.end())
		return &m_resourceArray[m_resourceCollection[_name]];
	else
		return nullptr;
}

} // namespace res
} // namespace sys
} // namespace pad