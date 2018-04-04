#include <iostream>

#include <Utilities/Serialization/Serialization.h>


int main()
{
	MAKE_META_DATA(toto, je, test);
	arr_toto;
	for (size_t i = 0; i < 2; i++)
		std::cout << arr_toto[i] << " ";
	std::cout << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}