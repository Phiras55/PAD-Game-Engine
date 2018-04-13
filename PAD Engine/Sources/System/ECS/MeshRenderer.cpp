#include <System/ECS/MeshRenderer.h>
#include <algorithm>

namespace pad	{
namespace sys	{
namespace ecs	{

std::vector<MeshRenderer> MeshRenderer::m_collection;

MeshRenderer::MeshRenderer()
{
	m_type = COMPONENT_TYPE::MESH_RENDERER;
}

MeshRenderer::~MeshRenderer()
{
//	m_collection.erase(std::remove(m_collection.begin(), m_collection.end(), *this), m_collection.end());
}

void MeshRenderer::Init()
{
	m_collection.push_back(*this);
}

void MeshRenderer::Start()
{

}

void MeshRenderer::Update()
{

}

void MeshRenderer::FixedUpdate()
{

}

void MeshRenderer::LateUpdate()
{

}

} // namespace ecs
} // namespace sys
} // namespace pad