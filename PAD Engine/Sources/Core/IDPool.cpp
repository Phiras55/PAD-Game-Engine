#include <Core/IDPool.h>

namespace pad	{
namespace core	{

IDPool::IDPool() : newId(0)
{

}

IDPool::~IDPool()
{

}

int IDPool::GenerateID()
{
	int result;
	size_t poolSize = pool.size();

	if (poolSize > 0)
	{
		result = pool[poolSize - 1];
		pool.pop_back();
		return result;
	}
	else
	{
		result = newId;
		++newId;
		return result;
	}
}

void IDPool::FreeID(const int _id)
{
	pool.push_back(_id);
}

} // namespace core
} // namespace pad