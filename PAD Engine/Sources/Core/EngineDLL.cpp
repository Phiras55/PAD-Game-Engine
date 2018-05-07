#include <EnginePCH.h>
#include <Core/EngineDLL.h>
#include <Core/Engine.h>

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

void InitEngine(const gfx::rhi::ContextSettings& _c, const gfx::win::WindowSettings& _w)
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

void AddPADObject(sys::ecs::PADObject* const _padObject)
{
	if(g_engine && g_engine->GetScene())
		g_engine->GetScene()->AddPADObject(_padObject);
}

void RemovePADObject(sys::ecs::PADObject* const _padObject)
{
	if(_padObject->GetParent())
		_padObject->GetParent()->RemoveChild(_padObject);
}

void MoveMainCamera(math::Vec3f& _translation)
{
	if (g_engine && g_engine->GetScene())
		g_engine->GetScene()->GetMainCamera().GetTransform().Move(_translation);
}

void RotateMainCamera(math::Vec3f& _rotation)
{
	if (g_engine && g_engine->GetScene())
		g_engine->GetScene()->GetMainCamera().GetTransform().SetRotation(_rotation);
}

void SetMainCameraTarget(const math::Vec3f& _targetPosition)
{
	if (g_engine && g_engine->GetScene())
	{
		sys::ecs::PerspectiveCamera& cam = g_engine->GetScene()->GetMainCamera();
		cam.LookAt(cam.GetTransform().Position(), _targetPosition, math::Vec3f::Up());
	}
}

void LoadResourceFile(const std::string& _filePath, const std::string& _outputPath)
{
	if (g_engine)
	{

	}
}

} // namespace pad