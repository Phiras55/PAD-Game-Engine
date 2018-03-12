#include <iostream>

#include <chrono>

#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Math/Matrix3x3.h>

using namespace pad;

void ArthurMathTest()
{
	auto Start = std::chrono::high_resolution_clock::now();

	math::Matrix3x3 mat	(1,2,3,4,5,6,7,8,9);
	math::Matrix3x3 mat2(1,2,3,4,5,6,7,8,8);
	
	for (size_t i = 0; i < 100000000; i++)
	{

	}

	auto End = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration<float>(End - Start).count() << std::endl;

	system("pause");
}

int main()
{
	ArthurMathTest();

	return EXIT_SUCCESS;
}