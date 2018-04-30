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
#include <Utilities/Serialization.h>

#undef main

struct bar : public ASerializable
{
	double a;
	float b;
	int c;

	json Serialize()
	{
		json j;
		AddDataToJson(j, "a", a);
		AddDataToJson(j, "b", b);
		AddDataToJson(j, "c", c);
		return j;
	}
	void Deserialize(const json& j) 
	{
		a = JsonToData<double>(j, "a");
		b = JsonToData<float>(j, "b");
		c = JsonToData<int>(j, "c");
	}

};

struct foo : public ASerializable
{
	double a;
	float b;
	int c;
	bar d;

	json Serialize()
	{
		json j;									// Fisrt, create an empty Json
		AddDataToJson(j, "a", a);				// Then add your data
		AddDataToJson(j, "b", b);
		AddDataToJson(j, "c", c);
		AddDataToJson(j, "d", d.Serialize());	//Add to the parent Json his child data
		return j;
	}
	void Deserialize(const json& j) 
	{
		a = JsonToData<double>(j, "a");
		b = JsonToData<float>(j, "b");
		c = JsonToData<int>(j, "c");
		d.Deserialize(JsonToData<json>(j, "d"));
	}
};

int mainSerialization()
{
	foo f;
	f.a = 6.2;
	f.b = 3.1f;
	f.c = 1;
	f.d.a = 1.2;
	f.d.b = 3.6f;
	f.d.c = 6;

	json j = f.Serialize();				//Serialization process -> gives a Json

	auto file = CreateFile("foo.json");	//Create the final file (no need to check the path, CreateFile() does it)
	AddJsonToFile(file, "foo", j);		//Add your Json to the file with a name
	file.close();


	json dj = LoadJsonFromFile("foo.json", "foo");
	foo f2;
	f2.Deserialize(dj);

	system("pause");

	return EXIT_SUCCESS;
}

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
	pad::gfx::rhi::shad::CustomUniform		albedoUniform;

	albedoUniform.data = &pad::math::Vec4f(0.f, 1.f, 0.f, 1.f);
	albedoUniform.type = pad::gfx::rhi::shad::DataType::VEC4;

	vertShader.LoadShader("../Resources/Shaders/basicPositions.vert");
	fragShader.LoadShader("../Resources/Shaders/basicColors.frag");

	program.SetVertexShader(&vertShader);
	program.SetFragmentShader(&fragShader);
	program.CompileProgram();

	#pragma region Ground

	pad::sys::ecs::PADObject* ground = new pad::sys::ecs::PADObject();
	pad::sys::ecs::MeshRenderer* ground_MR = new pad::sys::ecs::MeshRenderer();

	ground_MR->GetSettings().programs.push_back(&program);
	ground_MR->GetSettings().isWireframe = true;
	ground_MR->GetSettings().customUniforms["albedo"] = albedoUniform;
	ground_MR->SetMeshName("Cube");
	ground_MR->SetMaterialName("Default");
	ground_MR->GetTransform().SetScale(pad::math::Vec3f(10, 1, 10));

	pad::sys::ecs::RigidBody*	ground_RB		= new pad::sys::ecs::RigidBody();
	pad::sys::ecs::BoxCollider* ground_Collider = new pad::sys::ecs::BoxCollider(pad::math::Vec3f(10, 1, 10));
	ground_RB->SetMass(0.f);

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
		cube_MR->GetSettings().programs.push_back(&program);
		cube_MR->GetSettings().isWireframe = true;
		cube_MR->GetSettings().customUniforms["albedo"] = albedoUniform;
		cube_MR->SetMeshName("Cube");
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

	pad::StartSimulation();
	pad::DestroyEngine();
	return EXIT_SUCCESS;
}

