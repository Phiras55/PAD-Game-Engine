#include <iostream>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Core/Engine.h>
#include <vector>
#include <functional>

#include <Threading/ThreadPool.h>

#undef main

using namespace pad;

int main()
{
	core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();


	return EXIT_SUCCESS;
}