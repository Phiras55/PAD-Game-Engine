#include <PCH.h>
#include <Graphics/Model/MeshData.h>

namespace pad	{
namespace gfx	{
namespace mod	{

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
	delete[] positions;
	delete[] normals;
	delete[] uvs;
	delete[] indices;
}

} // namespace mod
} // namespace gfx
} // namespace pad