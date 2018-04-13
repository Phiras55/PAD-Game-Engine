#pragma once

template<typename T>
struct ISerializable
{
	virtual std::string Serialize()	= 0;
	virtual T Deserialize()	= 0;
};