#include <Core/IDPool.h>

namespace pad	{
namespace core	{

IDPool::IDPool() : m_newId(0)
{

}

IDPool::~IDPool()
{

}

int IDPool::GenerateID()
{
	int result;
	size_t poolSize = m_pool.size();

	if (poolSize > 0)
	{
		result = m_pool[poolSize - 1];
		m_pool.pop_back();
		return result;
	}
	else
	{
		result = m_newId;
		++m_newId;
		return result;
	}
}

void IDPool::FreeID(const int _id)
{
	m_pool.push_back(_id);
}

} // namespace core
} // namespace pad