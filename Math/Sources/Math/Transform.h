#pragma once

#include <Math/Matrix4x4.h>

namespace pad	{
namespace math	{

class Transform final
{
public:
	Transform()		= default;
	~Transform()	= default;

private:
	Mat4	localTransform;
	Mat4	globalTransform;
	Vec3f	position;
	Vec3f	rotation;
	Vec3f	scale;
	bool	isDirty;

private:
	void ComputeLocalMatrix();

public:
	inline const Mat4& GetGlobalTransform() const { return globalTransform; }

	const Mat4& GetLocalTransform();
	void SetGlobalTransform(const Mat4& _globalTransform);

	void SetPosition(const Vec3f& _position);
	void Move(const Vec3f& _movement);

	void SetRotation(const Vec3f& _rotation);

	void SetScale(const Vec3f& _scale);
	void SetScale(const float _scalar);
	void ScaleBy(const float _scalar);
};

} // namespace math
} // namespace pad