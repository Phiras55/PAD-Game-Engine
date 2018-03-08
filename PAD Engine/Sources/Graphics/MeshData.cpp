#include <Graphics/MeshData.h>

namespace pad {
namespace gfx {

	MeshData::MeshData() :
		positions(nullptr),
		normals(nullptr),
		uvs(nullptr),
		indices(nullptr),
		positionCount(0u),
		normalCount(0u),
		uvCount(0u),
		indiceCount(0u)
	{

	}

	MeshData::~MeshData()
	{
		if (positions)
			delete[] positions;
		if (normals)
			delete[] normals;
		if (uvs)
			delete[] uvs;
		if (indices)
			delete[] indices;
	}

} // namespace gfx
} // namespace pad