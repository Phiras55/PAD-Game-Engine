#pragma once
#include <System/WindowSettings.h>
#include <Graphics/RHI/ContextSettings.h>
#include <Graphics/RHI/RenderSettings.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/Model/MeshData.h>

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
	ENGINE_API void DebugGenerateMesh(gfx::mod::Mesh& _m, const gfx::mod::MeshData& _md);

	ENGINE_API void ClearBuffer();
	ENGINE_API void Draw(const gfx::mod::Mesh& _m, const gfx::rhi::RenderSettings& _settings);
	ENGINE_API void DebugDraw(const gfx::mod::Mesh& _m, const gfx::rhi::RenderSettings& _settings, const math::Mat4& _vp, const math::Vec4f& _albedo);
	ENGINE_API void SwapBuffers();

	ENGINE_API void ResizeViewport(const uint32 _w, const uint32 _h);
	ENGINE_API bool IsWindowOpen();
}