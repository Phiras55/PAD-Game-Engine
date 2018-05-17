#include <EnginePCH.h>
#include <System/ECS/Skeleton.h>

namespace pad	{
namespace sys	{
namespace ecs	{

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

} // namespace ecs
} // namespace sys
} // namespace pad