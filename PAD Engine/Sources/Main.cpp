#include <iostream>

#include <chrono>

#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Core/Engine.h>

#undef main

using namespace pad;

void ArthurMathTest()
{

}

int main()
{
	core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();

	return EXIT_SUCCESS;
}