#include <iostream>

#include <chrono>

#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Math/Matrix4x4.h>

using namespace pad;

void ArthurMathTest()
{
	auto Start = std::chrono::high_resolution_clock::now();
	


	auto End = std::chrono::high_resolution_clock::now();
	std::cout << std::endl << std::endl << std::endl <<
		"Duration: " << std::chrono::duration<float>(End - Start).count()<<
	std::endl << std::endl << std::endl;
	
	system("pause");
}

int main()
{

	return EXIT_SUCCESS;
}