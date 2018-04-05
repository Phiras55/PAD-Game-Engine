#include <System/Resource/MeshManager.h>

namespace pad	{
namespace sys	{
namespace res	{

MeshManager::MeshManager()
{
}

MeshManager::~MeshManager()
{
}

gfx::mod::Mesh* const MeshManager::GetResource(const std::string _name)
{
	if (m_resourceCollection.find(_name) != m_resourceCollection.end())
		return static_cast<gfx::mod::Mesh*>(m_resourceArray[m_resourceCollection[_name]]);
	else
		return nullptr;
}

} // namespace res
} // namespace sys
} // namespace pad