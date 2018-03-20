#include <iostream>
#include <Core/Engine.h>

#undef main

using namespace pad;

void MethodForTestingPurpose()
{
}

int main()
{
	MethodForTestingPurpose();

	core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();

	return EXIT_SUCCESS;
}