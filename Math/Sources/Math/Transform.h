#pragma once
#include <Math/MatrixTransform.h>
#include <Math/Vector4.h>

namespace pad	{
namespace math	{

using Mat4 = Matrix4x4;

class Transform final
{
public:
	inline Transform()		= default;
	inline ~Transform()		= default;

private:
	Mat4	m_localTransform;
	Mat4	m_globalTransform;
	Vec3f	m_position;
	Vec3f	m_rotation;
	Vec3f	m_scale;
	bool	m_isDirty;

public:
	inline const Vec3f& Position() const	{ return m_position; }
	inline const Vec3f& Rotation() const	{ return m_rotation; }
	inline const Vec3f& Scale() const		{ return m_scale; }

private:
	inline void ComputeLocalMatrix()
	{
		m_localTransform = TranslationMatrix(m_position)
			*	RotationMatrix()
			*	ScaleMatrix();

		m_isDirty = false;
	}

public:
	inline const Mat4& GetGlobalTransform() const { return m_globalTransform; }

	inline const Mat4& GetLocalTransform()
	{
		if (m_isDirty)
			ComputeLocalMatrix();

		return m_localTransform;
	}

	inline void SetGlobalTransform(const Mat4& _globalTransform)
	{
		m_globalTransform = _globalTransform;
	}

	inline void SetPosition(const Vec3f& _position)
	{
		m_position = _position;
		m_isDirty = true;
	}

	inline void Move(const Vec3f& _movement)
	{
		m_position += _movement;
		m_isDirty = true;
	}
	 
	inline void SetRotation(const Vec3f& _rotation)
	{
		m_rotation = _rotation;
		m_isDirty = true;
	}
	 
	inline void SetScale(const Vec3f& _scale)
	{
		m_scale = _scale;
		m_isDirty = true;
	}

	inline void SetScale(const float _scalar)
	{
		m_scale = Vec3f(_scalar, _scalar, _scalar);
		m_isDirty = true;
	}

	inline void ScaleBy(const float _scalar)
	{
		m_scale *= _scalar;
		m_isDirty = true;
	}
};

} // namespace math
} // namespace pad
