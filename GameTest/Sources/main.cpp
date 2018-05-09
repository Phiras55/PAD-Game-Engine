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
#include <System/ECS/BoxCollider.h>

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

	/*

	#pragma region Ground

	pad::sys::ecs::PADObject* ground = new pad::sys::ecs::PADObject();
	pad::sys::ecs::MeshRenderer* ground_MR = new pad::sys::ecs::MeshRenderer();

	ground_MR->GetSettings().isWireframe = true;
	ground_MR->SetMeshName("Default");
	ground_MR->SetMaterialName("Default");
	//ground_MR->GetTransform().SetScale(pad::math::Vec3f(10, 1, 10));

	pad::sys::ecs::RigidBody*	ground_RB		= new pad::sys::ecs::RigidBody();
	pad::sys::ecs::BoxCollider* ground_Collider = new pad::sys::ecs::BoxCollider(pad::math::Vec3f(10, 1, 10));
	ground_RB->SetMass(0.f);

	ground->GetTransform().SetScale(pad::math::Vec3f(10.f, 1.f, 10.f));
	ground->AddComponent(ground_MR);
	ground->AddComponent(ground_RB);
	ground->AddComponent(ground_Collider);

	pad::AddPADObject(ground);

	#pragma endregion

	#pragma region Falling Cube

	for (int i = 0; i < 10; ++i)
	{
		pad::sys::ecs::PADObject* cube = new pad::sys::ecs::PADObject();
		cube->GetTransform().SetPosition(pad::math::Vec3f(0, i *2 +10, 0));
		cube->GetTransform().SetRotation(pad::math::Vec3f(i * 45, i *45, i*45));

		pad::sys::ecs::MeshRenderer* cube_MR = new pad::sys::ecs::MeshRenderer();
		cube_MR->GetSettings().isWireframe = true;
		cube_MR->SetMeshName("Default");
		cube_MR->SetMaterialName("Default");

		pad::sys::ecs::RigidBody*	cube_RB = new pad::sys::ecs::RigidBody();
		pad::sys::ecs::BoxCollider* cube_Collider = new pad::sys::ecs::BoxCollider(pad::math::Vec3f(1, 1, 1));
		cube_RB->SetMass(10.f);

		cube->AddComponent(cube_MR);
		cube->AddComponent(cube_RB);
		cube->AddComponent(cube_Collider);

		pad::AddPADObject(cube);
	}

	#pragma endregion

	*/

	pad::StartSimulation();
	pad::DestroyEngine();

	return EXIT_SUCCESS;
}

