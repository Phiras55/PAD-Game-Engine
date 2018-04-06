#include <iostream>

#include <Utilities/Serialization/Serialization.h>


int main()
{
	MAKE_META_DATA(toto, je, test, de, serialize, de, la, data, et, ca, marche);
	meta_toto;
	for (size_t i = 0; i < 10; i++)
		std::cout << meta_toto[i] << " ";
	std::cout << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}