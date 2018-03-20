#include <iostream>
#include <Core/Engine.h>
#include <Math/Matrix4x4.h>

#undef main

using namespace pad;

void MethodForTestingPurpose()
{
	math::Matrix4x4 mat1;
	mat1.IsOrthogonal();
}

int main()
{
	MethodForTestingPurpose();

	core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();

	return EXIT_SUCCESS;
}