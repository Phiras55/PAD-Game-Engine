#include <EnginePCH.h>
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

#undef main

int main()
{
	#pragma region RenderInit

	pad::gfx::win::WindowSettings winSettings;

	winSettings.title			= "This is a SDL Window.";
	winSettings.position.x		= 400u;
	winSettings.position.y		= 200u;
	winSettings.size.x			= 1600u;
	winSettings.size.y			= 900u;
	winSettings.isFullscreen	= false;
	winSettings.windowType		= pad::gfx::win::E_WINDOW_TYPE::SDL;

	// Will be read from a config file
	pad::gfx::rhi::ContextSettings contextSettings;

	contextSettings.viewportSize.x		= winSettings.size.x;
	contextSettings.viewportSize.y		= winSettings.size.y;
	contextSettings.clearColor.r		= 0.3f;
	contextSettings.clearColor.g		= 0.3f;
	contextSettings.clearColor.b		= 0.3f;
	contextSettings.clearColor.a		= 1.0f;
	contextSettings.implementationType	= pad::gfx::rhi::E_RENDERER_IMPLEMENTATION_TYPE::OPENGL;
	contextSettings.cullFace			= pad::gfx::rhi::E_CULL_FACE::BACK;
	contextSettings.depthFunc			= pad::gfx::rhi::E_DEPTH_FUNCTION::LESS;
	contextSettings.windingOrder		= pad::gfx::rhi::E_WINDING_ORDER::COUNTER_CLOCKWISE;
	contextSettings.enabledBuffers		= pad::gfx::rhi::BufferType::ALL;

	#pragma endregion

	pad::CreateEngine();
	pad::InitEngine(contextSettings, winSettings);

	pad::gfx::gl::shad::GLShaderProgram		program;
	pad::gfx::gl::shad::GLFragmentShader	fragShader;
	pad::gfx::gl::shad::GLVertexShader		vertShader;

	vertShader.LoadShader("../Resources/Shaders/basicPositions.vert");
	fragShader.LoadShader("../Resources/Shaders/basicColors.frag");

	program.SetVertexShader(&vertShader);
	program.SetFragmentShader(&fragShader);
	program.CompileProgram();

	pad::sys::ecs::PADObject		obj1, obj2;
	pad::sys::ecs::RigidBody		rb;
	pad::sys::ecs::MeshRenderer		mr1(obj1.GetTransform());
	obj2.GetTransform().Move(pad::math::Vec3f(5.f, 0.f, 0.f));
	pad::sys::ecs::MeshRenderer		mr2(obj2.GetTransform());

	mr1.GetSettings().programs.push_back(&program);
	mr2.GetSettings().programs.push_back(&program);

	mr1.GetSettings().isWireframe = false;
	mr2.GetSettings().isWireframe = true;

	mr1.SetMeshName("Cube");
	mr2.SetMeshName("Cube");
	mr1.SetMaterialName("Default");
	mr2.SetMaterialName("Default");
	obj1.AddComponent(&rb);
	obj1.AddComponent(&mr1);
	pad::sys::ecs::MeshRenderer::AddToCollection(mr1);
	pad::sys::ecs::MeshRenderer::AddToCollection(mr2);

	pad::AddPADObject(&obj1);
	pad::AddPADObject(&obj2);

	pad::StartSimulation();
	pad::DestroyEngine();

	return EXIT_SUCCESS;
}