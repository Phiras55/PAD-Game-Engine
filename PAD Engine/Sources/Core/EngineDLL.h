#pragma once
#include <System/WindowSettings.h>
#include <Graphics/RHI/ContextSettings.h>
#include <Graphics/RHI/RenderSettings.h>
#include <Graphics/Model/Mesh.h>

#define ENGINE_API __declspec(dllexport)

namespace pad	
{
	ENGINE_API void CreateEngine();
	ENGINE_API void DestroyEngine();

	ENGINE_API void InitEngine();
	ENGINE_API void InitWindow(const sys::WindowSettings& _settings);
	ENGINE_API void InitRenderer(const gfx::rhi::ContextSettings& _settings);

	ENGINE_API void PollEvents();
	ENGINE_API void UpdateEngine();
	ENGINE_API void FixedUpdateEngine();

	ENGINE_API void ClearBuffer();
	ENGINE_API void Draw(const gfx::mod::Mesh& _m, const gfx::rhi::RenderSettings& _settings);
	ENGINE_API void SwapBuffers();

	ENGINE_API void ResizeViewport(const uint32 _w, const uint32 _h);
	ENGINE_API bool IsWindowOpen();
}