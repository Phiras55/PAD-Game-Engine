#pragma once
namespace pad	{
namespace util	{
using json = nlohmann::json;

class ISerializable
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

void AddJsonToFile(const std::string& path, const json& j);
json LoadJsonFromFile(const std::string& path);

template<typename T>
T JsonToData(const json& j, const std::string& name)
{
	return j.at(name).get<T>();
}

} // namespace util
} // namespace pad

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
	void Deserialize(const json& j) 
	{
		a = JsonToData<double>(j, "a");
		b = JsonToData<float>(j, "b");
		c = JsonToData<int>(j, "c");
	}

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
	void Deserialize(const json& j) 
	{
		a = JsonToData<double>(j, "a");
		b = JsonToData<float>(j, "b");
		c = JsonToData<int>(j, "c");
		d.Deserialize(JsonToData<json>(j, "d"));
	}
};

int mainSerialization()
{
	foo f;
	f.a = 6.2;
	f.b = 3.1f;
	f.c = 1;
	f.d.a = 1.2;
	f.d.b = 3.6f;
	f.d.c = 6;

	json j = f.Serialize();			//Serialization process -> gives a Json
	AddJsonToFile("foo.json", j);	//Add your Json to the file

	json dj = LoadJsonFromFile("foo.json");
	foo f2;
	f2.Deserialize(dj);
	std::cout	<< f.a		<< std::endl
				<< f.b		<< std::endl
				<< f.c		<< std::endl
				<< f.d.a	<< std::endl
				<< f.d.b	<< std::endl
				<< f.d.c	<< std::endl;
	system("pause");

	return EXIT_SUCCESS;
}*/