#pragma once
#include <Common.h>

namespace pad {
namespace gfx {

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

} // namespace gfx
} // namespace pad