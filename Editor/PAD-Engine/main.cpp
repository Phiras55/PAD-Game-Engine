#include <QApplication.h>
#include <QFile>
#include <QTextStream>

#include <padeditor.h>
#include <glwidget.h>
#include "ui_padeditor.h"

//#include <EnginePCH.h>
#include <Core/EngineDLL.h>
//#include <Graphics/GL/Shader/GLShaderProgram.h>
//#include <Graphics/GL/Shader/GLVertexShader.h>
//#include <Graphics/GL/Shader/GLFragmentShader.h>
//#include <System/ECS/PerspectiveCamera.h>
//#include <System/ECS/PADObject.h>
//#include <System/ECS/RigidBody.h>
//#include <Graphics/Model/Mesh.h>
//#include <Graphics/Model/MeshData.h>
//#include <System/ECS/MeshRenderer.h>
//#include <System/ECS/BoxCollider.h>
//#include <AssetParser/AssetReader.h>
//#include <AssetParser/AssetParser.h>

#undef main

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
    PADEditor w;
    w.show();

    pad::parser::ParseFile("..\\Resources\\FBX\\GiantSpider.fbx", "..\\Resources\\PADFormat\\");

    #pragma region RenderInit

    pad::gfx::win::WindowSettings winSettings;

    winSettings.title			= "This is a SDL Window.";
    winSettings.position.x		= 0u;
    winSettings.position.y		= 0u;
    winSettings.size.x			= 1600u;
    winSettings.size.y			= 900u;
    winSettings.isFullscreen	= false;
    winSettings.windowType		= pad::gfx::win::E_WINDOW_TYPE::QT;

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
    a.exec();
    return pad::DestroyEngine();;
}













/*
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

#include <padeditor.h>

#include <glwidget.h>

#define LOGGER


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
    PADEditor w;
    w.show();





#pragma region RenderInit

    pad::gfx::win::WindowSettings winSettings;

    winSettings.title			= "This is a Qt Window.";
    winSettings.position.x		= 0u;
    winSettings.position.y		= 0u;
    winSettings.size.x			= 720u;
    winSettings.size.y			= 480u;
    winSettings.isFullscreen	= false;
    winSettings.windowType		= pad::gfx::win::E_WINDOW_TYPE::QT;

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

    vertShader.LoadShader("Resources/Shaders/basicPositions.vert");
    fragShader.LoadShader("Resources/Shaders/basicColors.frag");

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
	pad::Simulate();
    return a.exec();
}
*/
