#include <iostream>

#include<Graphics/Renderer.h>
#include<Core/Engine.h>

#undef main

using namespace pad;

int main()
{
	core::Engine engine;

	engine.InitSimulation();
	engine.StartSimulation();

	return EXIT_SUCCESS;
}