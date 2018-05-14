#pragma once
namespace pad	{
namespace gfx	{
namespace mod	{

struct ControlPoint
{
	uint fbxIndice;
	uint myIndice;
};

struct MeshData
{
	MeshData();
	~MeshData();

	float*	positions;
	float*	normals;
	float*	uvs;
	uint32* indices;

	uint32 positionCount;
	uint32 normalCount;
	uint32 uvCount;
	uint32 indiceCount;

	ControlPoint* vertexInfo;
};

} // namespace mod
} // namespace gfx
} // namespace pad