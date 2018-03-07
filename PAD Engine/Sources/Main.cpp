#include <iostream>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>

#include <vld.h>

using namespace pad;

void DavidArthurMathTest()
{
	//math::Vec4<int> v1(1, 1, 1, 1);
	//math::Vec4f v2(2.5f, 4.0f, 2, 0);
	//math::Vec4d v3(1, 2, 4, 2);
	//math::Vec4i v4(0, 5, 7, 8);
	//math::Vec4u v5(0, 0, 0, 0);

	//std::cout << v1 << std::endl;
	//std::cout << v2 << std::endl;
	//std::cout << v3 << std::endl;
	//std::cout << v4 << std::endl;
	//std::cout << v5 << std::endl;

	math::Vec2<int> v1(3, 5);
	std::cout << v1.DotProduct(v1) << std::endl;
	v1 = v1.Normalize() + v1;

	math::Vec2<float> v2(v1);
	v1 = v1 + v2;
	v2.DotProduct(v1);
	std::cout << v1 << std::endl;

	math::Vec3<float> v3float(1, 1, 1);

	system("pause");
}

int main()
{
	DavidArthurMathTest();

	return EXIT_SUCCESS;
}