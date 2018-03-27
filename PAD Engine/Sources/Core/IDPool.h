#pragma once

#include <vector>

namespace pad	{
namespace core	{

class IDPool
{
public:
	IDPool();
	~IDPool();

private:
	std::vector<unsigned short>	pool;																/*!< A container for Ids that are free to be re-used */
	unsigned short				newId;																/*!< The new Id to be used if none are free in the pool */

public:
	int GenerateID();
	void FreeID(const int _id);

	int GetNewIdValue() const { return newId; }
};

} // namespace core
} // namespace pad