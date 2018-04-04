#include <iostream>
#include <Core/Engine.h>
#include <Math/Matrix4x4.h>

#undef main

using namespace pad;

void MethodForTestingPurpose()
{
	
}

int main()
{
	core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();

	return EXIT_SUCCESS;
}