#pragma once
#include <json-develop\single_include\nlohmann\json.hpp>
#include <fstream>

using json = nlohmann::json;

template<typename T>
struct ISerializable
{
	void Serialize(std::string path)
	{
		CreateFile(path, SerializeData());
	}
	virtual json SerializeData()	= 0;
	virtual T Deserialize()			= 0;
};

void CreateFile(std::string path, json j)
{
	std::ofstream f(path);
	f << j;
	f.close();
}

template<typename T>
void AddToJson(json& j, std::string name, T value)
{
	j[name] = value;
}