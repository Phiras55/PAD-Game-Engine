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

inline void ArthurThreadingTest()
{
	std::chrono::high_resolution_clock::time_point Start
		= std::chrono::high_resolution_clock::now();
	
	trp::ThreadPool	Pool(4);
	std::mutex m;
	for (std::uint32_t i = 0u; i < 80u; ++i)
	{
		Pool.Push([&m, &Start]()
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			auto End = std::chrono::high_resolution_clock::now();
			m.lock();
			std::cout << std::chrono::duration<float>(End - Start).count() << std::endl;
			m.unlock();
		});
	}
	auto End = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<float>(End - Start).count() << std::endl;
	while (true);
}

int main()
{
	ArthurThreadingTest();
	/*core::Engine engine;
	
	engine.InitSimulation();
	engine.StartSimulation();*/


	return EXIT_SUCCESS;
}