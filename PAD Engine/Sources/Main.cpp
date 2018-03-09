#include <iostream>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Math/Matrix4x4.h>

using namespace pad;

void ArthurMathTest()
{
	math::Matrix4x4 mat(1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7);

	mat.Transpose();

	std::cout << mat << std::endl;

	system("pause");
}

int main()
{
	ArthurMathTest();

	return EXIT_SUCCESS;
}