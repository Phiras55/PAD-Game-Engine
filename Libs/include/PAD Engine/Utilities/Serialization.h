#pragma once
#include <json/json.hpp>
#include <fstream>
#include <io.h>
#include <direct.h>

using json = nlohmann::json;

class ASerializable
{
public:
	virtual json	Serialize()					= 0;
	virtual void	Deserialize(const json& j)	= 0;
protected:
	template<typename T>
	void AddDataToJson(json& j, const std::string& name, const T& value)
	{
		j[name] = value;
	}
};

std::ofstream CreateFile(const std::string& path)
{
	if (!_access(path.c_str(), 0))
		_mkdir(path.c_str());
	return std::ofstream(path);
}

void AddJsonToFile(std::ofstream& file, const std::string& name, const json& j)
{
	file << name << j << "\n";
}

template<typename T>
T JsonToData(const json& j, const std::string& name)
{
	return j.at(name).get<T>();
}

json LoadJsonFromFile(const std::string& path, const std::string& name)
{
	json j;
	std::ifstream f(path);
	if (f.is_open())
	{
		if (f.good())
			f >> j;
		f.close();
	}
	return JsonToData<json>(j, name);
}

/*
Exemple :

struct bar : public ASerializable
{
	double a;
	float b;
	int c;
	
	json Serialize()
	{
		json j;
		AddDataToJson(j, "a", a);
		AddDataToJson(j, "b", b);
		AddDataToJson(j, "c", c);
		return j;
	}
	void Deserialize() {}
	
};

struct foo : public ASerializable
{
	double a;
	float b;
	int c;
	bar d;

	json Serialize()
	{
		json j;									// Fisrt, create an empty Json
		AddDataToJson(j, "a", a);				// Then add your data
		AddDataToJson(j, "b", b);
		AddDataToJson(j, "c", c);
		AddDataToJson(j, "d", d.Serialize());	//Add to the parent Json his child data
		return j;
	}
	void Deserialize() {}
};

int main()
{
	foo f;
	f.a = 6.2;
	f.b = 3.1f;
	f.c = 1;
	f.d.a = 1.2;
	f.d.b = 3.6f;
	f.d.c = 6;
	
	json j = f.Serialize();				//Serialization process -> gives a Json
	
	auto file = CreateFile("foo.json");	//Create the final file (no need to check the path, CreateFile() does it)
	AddJsonToFile(file, "foo", j);		//Add your Json to the file with a name
	file.close();
	
	return EXIT_SUCCESS;
}*/