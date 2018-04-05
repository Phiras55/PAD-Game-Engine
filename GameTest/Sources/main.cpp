#include <iostream>
#include <Math/Matrix4x4.h>
#include <Core/EngineDLL.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>
#include <System/ECS/PerspectiveCamera.h>

#include <System/ECS/PADObject.h>
#include <System/ECS/RigidBody.h>
#include <Graphics/Model/Mesh.h>
#include <Graphics/Model/MeshData.h>
#include <System/ECS/MeshRenderer.h>

//#include <glm/gtc/matrix_transform.hpp>

int main()
{
	#pragma region RenderInit

	pad::sys::win::WindowSettings winSettings;

	winSettings.title = "This is a SDL Window.";
	winSettings.position.x = 400u;
	winSettings.position.y = 200u;
	winSettings.size.x = 1600u;
	winSettings.size.y = 900u;
	winSettings.isFullscreen = false;
	winSettings.windowType = pad::sys::win::E_WINDOW_TYPE::SDL;

	// Will be read from a config file
	pad::gfx::rhi::ContextSettings contextSettings;

	contextSettings.viewportSize.x = winSettings.size.x;
	contextSettings.viewportSize.y = winSettings.size.y;
	contextSettings.clearColor.r = 0.3f;
	contextSettings.clearColor.g = 0.3f;
	contextSettings.clearColor.b = 0.3f;
	contextSettings.clearColor.a = 1.0f;
	contextSettings.areTrianglesCounterClockwise = true;
	contextSettings.enabledBuffers = pad::gfx::rhi::BufferType::ALL;

	#pragma endregion

	pad::CreateEngine();
	pad::InitEngine(contextSettings, winSettings);

	pad::sys::ecs::PADObject		obj;
	pad::sys::ecs::RigidBody		rb;
	pad::sys::ecs::MeshRenderer		mr;
	mr.SetMeshName("Cube");
	obj.AddComponent(&rb);
	obj.AddComponent(&mr);
	pad::sys::ecs::MeshRenderer::AddToCollection(mr);

	pad::AddPADObject(&obj);

	pad::StartSimulation();
	pad::DestroyEngine();

	return EXIT_SUCCESS;

}