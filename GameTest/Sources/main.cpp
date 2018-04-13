#include <iostream>

#include <Graphics/Model/Mesh.h>
#include <tuple>


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

	system("pause");

	return EXIT_SUCCESS;
}