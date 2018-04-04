#include <Core/EngineDLL.h>
#include <Core/Engine.h>
#include <Logger/SimpleLogger.h>

namespace pad	{

core::Engine* g_engine = nullptr;

void CreateEngine()
{
	if (!g_engine)
		g_engine = new core::Engine();
	else
		LOG_WARNING_S("The engine was already created.\n");
}

void DestroyEngine()
{
	if (g_engine)
		delete g_engine;
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void InitEngine(const gfx::rhi::ContextSettings& _c, const sys::win::WindowSettings& _w)
{
	if (g_engine)
		g_engine->InitSimulation(_c, _w);
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void StartSimulation()
{
	if (g_engine)
		g_engine->StartSimulation();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void Simulate()
{
	if (g_engine)
		g_engine->Simulate();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void AddPADObject()
{

}

void RemovePADObject()
{

}

void SetMainCamera()
{

}

void MoveMainCamera()
{

}

void RotateMainCamera()
{

}

void SetMainCameraTarget()
{

}


} // namespace pad