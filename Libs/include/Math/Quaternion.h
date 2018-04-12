#pragma once

#include <Math/Matrix4x4.h>

namespace pad	{
namespace math	{

struct Quaternion
{
	#pragma region Constructor / Destructor

	Quaternion() = default;
	Quaternion(const float _i, const float _j, const float _k, const float _scalar) :
		i(_i),
		j(_j),
		k(_k),
		scalar(_scalar) {}

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
};

using Quat = Quaternion;

} // namespace math
} // namespace pad

#include <Math/Quaternion_impl.h>