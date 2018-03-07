#include <iostream>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Core/Engine.h>

#include <Graphics/Renderer.h>
#include <Core/Engine.h>

#undef main

using namespace pad;

void DavidArthurMathTest()
{
	std::cout << core::EngineClock::GetDeltaTime() << std::endl;
}

int main()
{
	core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();

	DavidArthurMathTest();
	return EXIT_SUCCESS;
}