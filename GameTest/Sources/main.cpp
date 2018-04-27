#include <iostream>

#include <Graphics/Model/Mesh.h>
#include <tuple>
#include <Utilities\Serialization\Serialization.h>


class toto
{
public:
	double a;
	float b;
	int c;
};

int main()
{
	toto t;
	t.a = 6.2;
	t.b = 3.1f;
	t.c = 1;
	
	json j;
	AddToJson(j, "a", t.a);
	AddToJson(j, "b", t.b);
	AddToJson(j, "c", t.c);
	auto f = CreateFile("toto.json", j);
	f.close();

	system("pause");

	return EXIT_SUCCESS;
}