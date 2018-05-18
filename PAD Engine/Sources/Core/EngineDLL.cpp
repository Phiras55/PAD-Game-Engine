#include <EnginePCH.h>
#include <Core/EngineDLL.h>
#include <Core/Engine.h>
//#include <Shlwapi.h>
#include <AssetParser/AssetReader.h>
#include <stb_image/stb_image.h>
#include <Graphics/GL/GLTexture.h>
#include <Math/Transform.h>

//#pragma comment(lib,"shlwapi.lib")

namespace pad	{

core::Engine* g_engine = nullptr;

void CreateEngine()
{
	if (!g_engine)
		g_engine = new core::Engine();
	else
		LOG_WARNING_S("The engine was already created.\n");
}

void DestroyEngine()
{
	if (g_engine)
		delete g_engine;
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void InitEngine(const gfx::rhi::ContextSettings& _c, const gfx::win::WindowSettings& _w)
{
	if (g_engine)
		g_engine->InitSimulation(_c, _w);
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void StartSimulation()
{
	if (g_engine)
		g_engine->StartSimulation();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void Simulate()
{
	if (g_engine)
		g_engine->Simulate();
	else
		LOG_ERROR_S("Error! Call CreateEngine() first.\n");
}

void AddPADObject(sys::ecs::PADObject* const _padObject)
{
	if(g_engine && g_engine->GetScene())
		g_engine->GetScene()->AddPADObject(_padObject);
}

void RemovePADObject(sys::ecs::PADObject* const _padObject)
{
	if(_padObject->GetParent())
		_padObject->GetParent()->RemoveChild(_padObject);
}

void MoveMainCamera(math::Vec3f& _translation)
{
	if (g_engine && g_engine->GetScene()) 
		g_engine->GetScene()->GetMainCamera().GetTransform().Move(_translation);
}

void RotateMainCamera(math::Vec3f& _rotation)
{
	if (g_engine && g_engine->GetScene())
		g_engine->GetScene()->GetMainCamera().GetTransform().SetRotation(_rotation);
}

void SetMainCameraTarget(const math::Vec3f& _targetPosition)
{
	if (g_engine && g_engine->GetScene())
	{
		sys::ecs::PerspectiveCamera& cam = g_engine->GetScene()->GetMainCamera();
		cam.LookAt(cam.GetTransform().Position(), _targetPosition, math::Vec3f::Up());
	}
}

void LoadResourceFile(const std::string& _filePath, const std::string& _outputPath)
{
	if (g_engine)
	{
		std::string ext = pad::parser::GetFileExt(_filePath);
		if (ext == ".PADMesh")
			LoadMeshFile(_filePath);
		else if (ext == ".PADMaterial")
			LoadMaterialFile(_filePath);
		else if (ext == ".png" || ext == ".jpg")
			LoadTextureFile(_filePath);
		else if (ext == ".PADSkeleton")
			LoadSkeletonFile(_filePath);
		else if (ext == ".PADAnim")
			LoadAnimFile(_filePath);
	}
}

void LoadMeshFile(const std::string& _filePath)
{
	std::string	name = pad::parser::GetFileNameNoExt(_filePath);
	if (!g_engine->GetResourceManager()->GetMeshManager().GetResource(name))
	{
		gfx::mod::MeshData	meshData;
		gfx::mod::Mesh		mesh;

		parser::ReadPADMesh(_filePath, meshData);

		g_engine->GetRenderer().GenerateMesh(mesh, meshData);
		g_engine->GetResourceManager()->GetMeshManager().AddResource(name, mesh);
	}
}

void LoadSkeletonFile(const std::string& _filePath)
{
	gfx::mod::Skeleton skeleton;
	std::string name = pad::parser::GetFileNameNoExt(_filePath);
	if (!g_engine->GetResourceManager()->GetSkeletonManager().GetResource(name))
	{
		parser::ReadPADSkeleton(_filePath, skeleton);
		g_engine->GetResourceManager()->GetSkeletonManager().AddResource(name, skeleton);
	}
}

void LoadMaterialFile(const std::string& _filePath)
{
	std::string name = pad::parser::GetFileNameNoExt(_filePath);
	if (!g_engine->GetResourceManager()->GetMaterialManager().GetResource(name))
	{
		std::string name = pad::parser::GetFileNameNoExt(_filePath);

		gfx::mod::MaterialData	materialData;
		gfx::mod::Material		material;
		gfx::mod::TextureData	textureData;
		gfx::gl::GLTexture*		texture = new gfx::gl::GLTexture();

		parser::ReadPADMaterial(_filePath, materialData, textureData);

		material.SetAmbient(materialData.m_ambient);
		material.SetDiffuse(materialData.m_diffuse);
		material.SetSpecular(materialData.m_specular);
		material.SetShiness(materialData.m_shiness);
		material.SetName(materialData.m_name);

		gfx::rhi::TextureParameters param;
		param.sWrap = gfx::rhi::E_WRAP_TYPE(textureData.m_sWrap);
		param.tWrap = gfx::rhi::E_WRAP_TYPE(textureData.m_tWrap);
		param.channelType = gfx::rhi::E_CHANNEL_TYPE(textureData.m_channel);
		texture->SetName(textureData.m_name);
		g_engine->GetRenderer().GenerateTexture(texture, textureData.m_path, param);

		material.SetAlbedoMapName(textureData.m_name);

		g_engine->GetResourceManager()->GetMaterialManager().AddResource(name, material);
		g_engine->GetResourceManager()->GetTextureManager().AddResource(texture->GetName(), texture);
	}
}

void LoadTextureFile(const std::string& _filePath)
{
	std::string name = pad::parser::GetFileNameNoExt(_filePath);
	if (!g_engine->GetResourceManager()->GetTextureManager().GetResource(name))
	{
		std::string	name = pad::parser::GetFileNameNoExt(_filePath);

		gfx::gl::GLTexture* texture = new gfx::gl::GLTexture();
		gfx::rhi::TextureParameters param;
		texture->SetName(name);
		g_engine->GetRenderer().GenerateTexture(texture, _filePath, param);
		g_engine->GetResourceManager()->GetTextureManager().AddResource(texture->GetName(), texture);
	}
}

void LoadAnimFile(const std::string& _filePath)
{
	gfx::mod::Anim anim;
	std::string name = pad::parser::GetFileNameNoExt(_filePath);
	if (!g_engine->GetResourceManager()->GetAnimManager().GetResource(name))
	{
		parser::ReadPADAnim(_filePath, anim);
		g_engine->GetResourceManager()->GetAnimManager().AddResource(name, anim);
	}
}

sys::ecs::PADObject* GetPADObject(const std::string& _name, sys::ecs::PADObject* const _rootSearch)
{
	sys::ecs::PADObject* entity = nullptr;

	if (g_engine)
	{
		sys::ecs::Scene* currentScene = g_engine->GetScene();
		if (currentScene)
			entity = currentScene->GetPADObject(_name, _rootSearch);
	}

	return entity;
}

sys::ecs::PADObject* CreatePADObject(const std::string& _name, sys::ecs::PADObject* const _parent)
{
	sys::ecs::PADObject* entity = nullptr;

	if (g_engine)
	{
		sys::ecs::Scene* currentScene = g_engine->GetScene();
		if(currentScene)
			entity = currentScene->CreatePADObject(_name, _parent);
	}

	return entity;
}

void DeletePADObject(const std::string& _name, sys::ecs::PADObject* const _rootSearch)
{
	if (g_engine)
	{
		sys::ecs::Scene* currentScene = g_engine->GetScene();
		if (currentScene)
			currentScene->DeletePADObject(_name, _rootSearch);
	}
}

}
// namespace pad