#pragma once
#include <System/Window/WindowSettings.h>
#include <Graphics/RHI/ContextSettings.h>
#include <Utilities/Export.h>

namespace pad	
{
	ENGINE_API void CreateEngine();
	ENGINE_API void InitEngine(const gfx::rhi::ContextSettings& _c, const sys::win::WindowSettings& _w);
	ENGINE_API void DestroyEngine();

	ENGINE_API void StartSimulation();
	ENGINE_API void Simulate();

	ENGINE_API void AddPADObject();
	ENGINE_API void RemovePADObject();

	ENGINE_API void SetMainCamera();
	ENGINE_API void MoveMainCamera();
	ENGINE_API void RotateMainCamera();
	ENGINE_API void SetMainCameraTarget();
}