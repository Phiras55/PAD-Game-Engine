#pragma once
namespace pad	{
namespace gfx	{
namespace mod	{

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
};

} // namespace mod
} // namespace gfx
} // namespace pad