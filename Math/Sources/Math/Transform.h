#pragma once
#include <Json/Serialization.h>
#include <Math/MatrixTransform.h>
#include <Math/Vector4.h>
#include <Math/Quaternion.h>

#define PI 3.14159265359f

namespace pad	{
namespace math	{
	
inline float DegreeToRad(const float _deg) { return (_deg * PI) / 180.f; }
inline float RadToDegree(const float _rad) { return (_rad * 180.f) / PI; }

#define DEGREE_TO_RAD(x) pad::math::DegreeToRad(x)
#define RAD_TO_DEGREE(x) pad::math::RadToDegree(x)

using Mat4 = Matrix4x4;

class Transform final : public ISerializable
{
public:
	inline Transform() :
		m_scale(math::Vec3f(1.f, 1.f, 1.f))
	{
	}

	inline ~Transform()		= default;

private:
	Mat4	m_localTransform;
	Mat4	m_globalTransform;
	Quat	m_quatRotation;
	Vec3f	m_position;
	Vec3f	m_rotation;
	Vec3f	m_scale;
	bool	m_isDirty;

public:
	inline const Vec3f& Position() const	{ return m_position; }
	inline const Vec3f& Rotation() const	{ return m_rotation; }
	inline const Quat&	QuatRotation()const { return m_quatRotation; }
	inline const Vec3f& Scale() const		{ return m_scale; }

	json Serialize() override
	{
		json j;

		AddDataToJson(j, "m_localTransform",	m_localTransform.Serialize());
		AddDataToJson(j, "m_globalTransform",	m_globalTransform.Serialize());
		AddDataToJson(j, "m_quatRotation",		m_quatRotation.Serialize());
		AddDataToJson(j, "m_position",			m_position.Serialize());
		AddDataToJson(j, "m_rotation",			m_rotation.Serialize());
		AddDataToJson(j, "m_scale",				m_scale.Serialize());
		AddDataToJson(j, "m_isDirty",			m_isDirty);

		return j;
	}

	void Deserialize(const json& j)	override
	{
		m_localTransform.Deserialize(	JsonToData<json>(j, "m_localTransform"));
		m_globalTransform.Deserialize(	JsonToData<json>(j, "m_globalTransform"));
		m_quatRotation.Deserialize(		JsonToData<json>(j, "m_quatRotation"));
		m_position.Deserialize(			JsonToData<json>(j, "m_position"));
		m_rotation.Deserialize(			JsonToData<json>(j, "m_rotation"));
		m_scale.Deserialize(			JsonToData<json>(j, "m_scale"));
		m_isDirty = JsonToData<bool>(j, "m_isDirty");
	}

private:
	inline void ComputeLocalMatrix()
	{
		m_localTransform =		TranslationMatrix(m_position)
							*	RotationMatrix(m_quatRotation)
							*	ScaleMatrix(m_scale);

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
		m_quatRotation = Quat(	DEGREE_TO_RAD(_rotation.x),
								DEGREE_TO_RAD(_rotation.y),
								DEGREE_TO_RAD(_rotation.z));
		m_isDirty = true;
	}
	 
	inline void SetQuatRotation(const Quat& _quat)
	{
		m_quatRotation = _quat;
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
