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
#include <AssetParser/AssetReader.h>
#include <AssetParser/AssetParser.h>

#undef main

int main()
{
	//pad::parser::ParseFile("D:\\Projects\\PFA\\PAD-Game-Engine\\Resources\\FBX\\GiantSpider.fbx", "D:\\Projects\\PFA\\PAD-Game-Engine\\Resources\\FBX\\");

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
	contextSettings.clearColor.r		= 150.f / 255.f;
	contextSettings.clearColor.g		= 150.f / 255.f;
	contextSettings.clearColor.b		= 150.f / 255.f;
	contextSettings.clearColor.a		= 1.0f;
	contextSettings.implementationType	= pad::gfx::rhi::E_RENDERER_IMPLEMENTATION_TYPE::OPENGL;
	contextSettings.cullFace			= pad::gfx::rhi::E_CULL_FACE::BACK;
	contextSettings.depthFunc			= pad::gfx::rhi::E_DEPTH_FUNCTION::LESS;
	contextSettings.windingOrder		= pad::gfx::rhi::E_WINDING_ORDER::COUNTER_CLOCKWISE;
	contextSettings.enabledBuffers		= pad::gfx::rhi::BufferType::ALL;

	#pragma endregion

	pad::CreateEngine();
	pad::InitEngine(contextSettings, winSettings);

	pad::sys::ecs::PADObject* plat = pad::CreatePADObject("Platform");
	plat->AddComponent<pad::sys::ecs::MeshRenderer>("Cube", "Default");

	pad::LoadResourceFile("../Resources/PADFormat\\creature_pitlord_magtheridon_0.PADMaterial", "");
	pad::LoadResourceFile("../Resources/PADFormat\\creature_pitlord_magtheridon.PADMesh", "");
	pad::LoadResourceFile("../Resources/PADFormat\\creature_giantspider_giantspider_0.PADMaterial", "");
	pad::LoadResourceFile("../Resources/PADFormat\\creature_giantspider_giantspider.PADMesh", "");
	pad::LoadResourceFile("../Resources/PADFormat\\Grid.PADMaterial", "");
	pad::LoadResourceFile("../Resources/PADFormat\\Default.PADMaterial", "");

	plat->GetTransform().SetScale(pad::math::Vec3f(10.f, 1.f, 10.f));

	pad::sys::ecs::MeshRenderer* mr = plat->GetComponent<pad::sys::ecs::MeshRenderer>();

	plat->AddComponent<pad::sys::ecs::BoxCollider>(pad::math::Vec3f(10.f, 1.f, 10.f));
	plat->AddComponent<pad::sys::ecs::RigidBody>();
	pad::sys::ecs::RigidBody* rb = plat->GetComponent<pad::sys::ecs::RigidBody>();
	rb->SetMass(0.f);

	for (int i = 0; i < 10; ++i)
	{
		pad::sys::ecs::PADObject* cube = pad::CreatePADObject(std::string("Cube_0") + std::to_string(i));

		cube->GetTransform().SetPosition(pad::math::Vec3f(0, i * 2 + 10, 0));
		cube->GetTransform().SetRotation(pad::math::Vec3f(i * 45, i * 45, i * 45));
		cube->GetTransform().SetScale(0.01f);

		cube->AddComponent<pad::sys::ecs::MeshRenderer>("creature_giantspider_giantspider", "creature_giantspider_giantspider_0");
		cube->AddComponent<pad::sys::ecs::BoxCollider>(pad::math::Vec3f(1.f, 1.f, 1.f));
		cube->AddComponent<pad::sys::ecs::RigidBody>();

		rb = cube->GetComponent<pad::sys::ecs::RigidBody>();
		rb->SetMass(10.f);
	}

	pad::sys::ecs::PADObject* grid = pad::CreatePADObject("Grid");
	grid->AddComponent<pad::sys::ecs::MeshRenderer>("Quad", "Grid");
	grid->GetTransform().SetRotation(pad::math::Vec3f(-90.f, 0.f, 0.f));
	grid->GetTransform().SetScale(100.f);

	pad::StartSimulation();
	pad::DestroyEngine();

	return EXIT_SUCCESS;
}

