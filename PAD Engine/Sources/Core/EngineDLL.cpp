#include <Core/EngineDLL.h>
#include <Core/Engine.h>
#include <Logger/SimpleLogger.h>

namespace pad	
{
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

void InitEngine()
{
	if (g_engine)
		g_engine->InitSimulation();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void InitWindow(const sys::WindowSettings& _settings)
{
	if (g_engine)
		g_engine->CreateWindow(_settings);
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void InitRenderer(const gfx::rhi::RenderSettings& _settings)
{
	if (g_engine)
		g_engine->CreateRenderer(_settings);
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void PollEvents()
{
	if (g_engine)
	{
		g_engine->PollEvents();
		g_engine->FlushLogs();
	}
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void UpdateEngine()
{
	if (g_engine)
		g_engine->Update();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void FixedUpdateEngine()
{
	if (g_engine)
		g_engine->FixedUpdate();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void ClearBuffer()
{
	if (g_engine)
		g_engine->ClearBuffer();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void SwapBuffers()
{
	if (g_engine)
		g_engine->SwapBuffers();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void Draw(const gfx::mod::Mesh& _m)
{
	if (g_engine)
		g_engine->Draw(_m);
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

}