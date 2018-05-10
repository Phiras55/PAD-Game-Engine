#pragma once
#include <Graphics/Window/WindowSettings.h>
#include <PADRenderer/Graphics/RHI/ContextSettings.h>
#include <System/ECS/PADObject.h>

#include <Utilities/Export.h>

namespace pad	
{
	ENGINE_API void CreateEngine();
	ENGINE_API void InitEngine(const gfx::rhi::ContextSettings& _c, const gfx::win::WindowSettings& _w);
	ENGINE_API void DestroyEngine();

	ENGINE_API void StartSimulation();
	ENGINE_API void Simulate();

	ENGINE_API void AddPADObject(sys::ecs::PADObject* const _padObject);
	ENGINE_API void RemovePADObject(sys::ecs::PADObject* const _padObject);

	ENGINE_API void MoveMainCamera(const math::Vec3f& _translation);
	ENGINE_API void RotateMainCamera(const math::Vec3f& _rotation);
	ENGINE_API void SetMainCameraTarget(const math::Vec3f& _targetPosition);

	ENGINE_API void LoadResourceFile(const std::string& _filePath, const std::string& _outputPath);
	ENGINE_API void LoadMeshFile(const std::string& _filePath);
	ENGINE_API void LoadMaterialFile(const std::string& _filePath);
}