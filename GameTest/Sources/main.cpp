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
#include <System/ECS/BoxCollider.h>

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

	for (int i = 0; i < 5; ++i)
	{
		pad::sys::ecs::PADObject*		obj = new pad::sys::ecs::PADObject();
		obj->SetName("Physic Cube");
		obj->GetTransform().SetPosition(pad::math::Vec3f(i *0.5, i * 1.5 + 5, 0));
		pad::sys::ecs::RigidBody*		rb = new pad::sys::ecs::RigidBody();
		pad::sys::ecs::MeshRenderer*	mr = new pad::sys::ecs::MeshRenderer();
		pad::sys::ecs::BoxCollider*		box = new pad::sys::ecs::BoxCollider();
		mr->SetMeshName("Cube");
		obj->AddComponent(box);
		obj->AddComponent(rb);
		obj->AddComponent(mr);
		rb->SetMass(100);
		pad::sys::ecs::MeshRenderer::AddToCollection(*mr);
		pad::AddPADObject(obj);
	}

	pad::sys::ecs::PADObject*		obj2 = new pad::sys::ecs::PADObject();
	obj2->SetName("ground");
	obj2->GetTransform().SetPosition(pad::math::Vec3f(0, -2, 0));
	obj2->GetTransform().SetScale(pad::math::Vec3f(10, 0.1, 10));

	pad::sys::ecs::BoxCollider*		box2 = new pad::sys::ecs::BoxCollider(pad::math::Vec3f(5, 0.05, 5));
	pad::sys::ecs::RigidBody*		rb2 = new pad::sys::ecs::RigidBody();
	pad::sys::ecs::MeshRenderer*	mr2 = new pad::sys::ecs::MeshRenderer();
	mr2->SetMeshName("Cube");

	rb2->SetMass(0.f);
	obj2->AddComponent(mr2);
	obj2->AddComponent(box2);
	obj2->AddComponent(rb2);
	pad::sys::ecs::MeshRenderer::AddToCollection(*mr2);
	pad::AddPADObject(obj2);

	pad::StartSimulation();
	pad::DestroyEngine();

	return EXIT_SUCCESS;
}