#pragma once

#include <string>
#include <vector>
#include <Math/Matrix4x4.h>
#include <Utilities/Export.h>

namespace pad	{
namespace gfx	{
namespace mod	{

struct ENGINE_API Bone
{
	int			m_id;
	int			m_parentId;
	std::string m_name;
	math::Mat4	m_inverseBindPose;
};

class ENGINE_API Skeleton
{
public:
	Skeleton();
	~Skeleton();

private:
	std::string			m_name;
	int					m_boneCount;
	std::vector<Bone>	m_bones;

public:
	Bone* const GetBoneByName(const std::string& _boneName);

	inline void SetName(const std::string& _name)	{ m_name = _name; }
	inline void SetBoneCount(const int _boneCount)	{ m_boneCount = _boneCount; }
	inline void AddBone(const Bone& _bone)			{ m_bones.push_back(_bone); }

	inline const std::string& GetName() const		{ return m_name; }
};

} // namespace mod
} // namespace gfx
} // namespace pad