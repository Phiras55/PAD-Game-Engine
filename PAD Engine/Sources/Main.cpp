#include <iostream>
#include <Core/Engine.h>
#include <SimpleLogger.h>

#undef main

using namespace pad;

void MethodForTestingPurpose()
{
	LOG_INIT();

	LOG_INFO("Too much arguments and no delimiter.\n", 1, 2, 3, 4, 5);

	LOG_FLUSH();
}

int main()
{
	MethodForTestingPurpose();

	core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();

	return EXIT_SUCCESS;
}