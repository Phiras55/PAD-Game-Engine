#pragma once
#include <Json/Serialization.h>
#include <Math/Matrix4x4.h>

namespace pad	{
namespace math	{

struct Quaternion final : public ISerializable
{
	#pragma region Constructor / Destructor

	Quaternion() :
		i(0.f),
		j(0.f),
		k(0.f),
		scalar(1.f) {}

	Quaternion(const float _i, const float _j, const float _k, const float _scalar) :
		i(_i),
		j(_j),
		k(_k),
		scalar(_scalar) {}

	Quaternion(const Vec3f& _vec3)
	{
		float cos_yaw	= cos(_vec3.z * .5f);
		float sin_yaw	= sin(_vec3.z * .5f);
		float cos_roll	= cos(_vec3.x * .5f);
		float sin_roll	= sin(_vec3.x * .5f);
		float cos_pitch = cos(_vec3.y * .5f);
		float sin_pitch = sin(_vec3.y * .5f);

		i		= (cos_yaw * sin_roll * cos_pitch) - (sin_yaw * cos_roll * sin_pitch);
		j		= (cos_yaw * cos_roll * sin_pitch) + (sin_yaw * sin_roll * cos_pitch);
		k		= (sin_yaw * cos_roll * cos_pitch) - (cos_yaw * sin_roll * sin_pitch);
		scalar	= (cos_yaw * cos_roll * cos_pitch) + (sin_yaw * sin_roll * sin_pitch);
	}

	Quaternion(const float _roll, const float _pitch, const float _yaw)
	{
		float cos_yaw	= cos(_yaw		* .5f);
		float sin_yaw	= sin(_yaw		* .5f);
		float cos_roll	= cos(_roll		* .5f);
		float sin_roll	= sin(_roll		* .5f);
		float cos_pitch = cos(_pitch	* .5f);
		float sin_pitch = sin(_pitch	* .5f);

		i		= (cos_yaw * sin_roll * cos_pitch) - (sin_yaw * cos_roll * sin_pitch);
		j		= (cos_yaw * cos_roll * sin_pitch) + (sin_yaw * sin_roll * cos_pitch);
		k		= (sin_yaw * cos_roll * cos_pitch) - (cos_yaw * sin_roll * sin_pitch);
		scalar	= (cos_yaw * cos_roll * cos_pitch) + (sin_yaw * sin_roll * sin_pitch);
	}

	Quaternion(const Vec3f& _vec3, const float _scalar) :
		i(_vec3.x),
		j(_vec3.y),
		k(_vec3.z),
		scalar(_scalar) {}

	Quaternion(const Vec4f& _vec4)	:
		i(_vec4.x),
		j(_vec4.y),
		k(_vec4.z),
		scalar(_vec4.w) {}

	Quaternion(const Mat4& _matrix)
	{
		scalar	= (sqrt(1 + _matrix[0][0] + _matrix[1][1] + _matrix[2][2])) / 2.f;
		i		= (sqrt(1 + _matrix[0][0] - _matrix[1][1] - _matrix[2][2])) / 2.f;
		j		= (sqrt(1 - _matrix[0][0] + _matrix[1][1] - _matrix[2][2])) / 2.f;
		k		= (sqrt(1 - _matrix[0][0] - _matrix[1][1] + _matrix[2][2])) / 2.f;
	}

	~Quaternion() = default;

	#pragma endregion

	#pragma region Variables

	union {
		struct	{	float x;																			
					float y;																			
					float z;																			
					float w;																			
				};
		struct	{	float i;																	
					float j;																			
					float k;																			
					float scalar;																			
				};
		__m128 __DATA128;																			
	};

	#pragma endregion

	json Serialize() override
	{
		json j;

		AddDataToJson(j, "x", x);
		AddDataToJson(j, "y", y);
		AddDataToJson(j, "z", z);
		AddDataToJson(j, "w", w);

		return j;
	}

	void Deserialize(const json& j)	override
	{
		x = JsonToData<float>(j, "x");
		y = JsonToData<float>(j, "y");
		z = JsonToData<float>(j, "z");
		w = JsonToData<float>(j, "w");
	}
};

using Quat = Quaternion;

} // namespace math
} // namespace pad

#include <Math/Quaternion_impl.h>