#include <PCH.h>
#include <Graphics/Model/Skeleton.h>

namespace pad	{
namespace gfx	{
namespace mod	{

Skeleton::Skeleton()
{
}

Skeleton::~Skeleton()
{
}

Bone* const Skeleton::GetBoneByName(const std::string& _boneName)
{
	for (int boneIndex = 0; boneIndex < m_bones.size(); ++boneIndex)
	{
		if (m_bones[boneIndex].m_name == _boneName)
			return &m_bones[boneIndex];
	}
	return nullptr;
}

} // namespace mod
} // namespace gfx
} // namespace pad