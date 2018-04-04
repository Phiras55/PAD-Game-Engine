#include <iostream>

#include <Math/Matrix4x4.h>
#include <Core/EngineDLL.h>
#include <Graphics/GL/Shader/GLShaderProgram.h>
#include <Graphics/GL/Shader/GLVertexShader.h>
#include <Graphics/GL/Shader/GLFragmentShader.h>
#include <System/ECS/PerspectiveCamera.h>
#include <System/ECS/PADObject.h>
#include <System/ECS/RigidBody.h>

int main()
{
	// Will be read from a config file
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

	pad::CreateEngine();
	pad::InitEngine(contextSettings, winSettings);

	pad::StartSimulation();

	pad::DestroyEngine();

	/*pad::gfx::gl::shad::GLShaderProgram		program;
	pad::gfx::gl::shad::GLFragmentShader	fragShader;
	pad::gfx::gl::shad::GLVertexShader		vertShader;

	vertShader.LoadShader("../Resources/Shaders/basicPositions.vert");
	fragShader.LoadShader("../Resources/Shaders/basicColors.frag");

	program.SetVertexShader(&vertShader);
	program.SetFragmentShader(&fragShader);
	program.CompileProgram();

	#pragma endregion

	#pragma region Mesh
	
	pad::gfx::mod::Mesh m;
	pad::gfx::mod::MeshData md;
	pad::gfx::rhi::RenderSettings r;

	r.shaders.push_back(&program);
	r.isWireframe = true;

	md.positions = new float[24]{
		-0.5, -0.5,  0.5,
		 0.5, -0.5,  0.5,
		-0.5,  0.5,  0.5,
		 0.5,  0.5, -0.5,
		-0.5, -0.5, -0.5,
		-0.5,  0.5, -0.5,
		 0.5, -0.5, -0.5,
		 0.5,  0.5,  0.5
	};

	md.positionCount = 24;

	md.indices = new pad::uint32[36]{
		0, 1, 2,
		3, 4, 5,
		4, 3, 6,
		7, 2, 1,
		4, 6, 1,
		4, 2, 5,
		7, 1, 6,
		5, 2, 7,
		4, 0, 2,
		6, 3, 7,
		1, 0, 4,
		7, 3, 5
	};

	md.indiceCount = 36;*/

	return EXIT_SUCCESS;
}