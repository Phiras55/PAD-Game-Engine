#pragma once
#include <Common.h>

namespace pad	{
namespace util	{
	inline const uint64 GenerateUniqueID()
	{
		static uint64 uniqueID = 0;
		return uniqueID++;
	}

	template<class T>
	inline const uint64 GetTypeID()
	{
		static uint64 uniqueTypeID(GenerateUniqueID());
		return uniqueTypeID;
	}
}
}