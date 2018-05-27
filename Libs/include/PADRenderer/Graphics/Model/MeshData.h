#pragma once
namespace pad	{
namespace gfx	{
namespace mod	{

struct MeshData
{
	MeshData();
	~MeshData();

	float32*	positions;
	float32*	normals;
	float32*	uvs;
	uint32*		indices;
	float32*	boneIndex;
	float32*	boneWeight;

	uint32		positionCount;
	uint32		normalCount;
	uint32		uvCount;
	uint32		indiceCount;
	uint32		boneIndexCount;
	uint32		boneWeightCount;
};

} // namespace mod
} // namespace gfx
} // namespace pad