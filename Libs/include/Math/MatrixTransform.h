#pragma once
#include <math.h>
#include <Math/Matrix4x4.h>
#include <Math/Quaternion.h>

namespace pad	{
namespace math	{

inline Matrix4x4 TranslationMatrix(float _x= 0.f, float _y = 0.f, float _z = 0.f)
{
	return Matrix4x4(	1, 0, 0,_x,
						0, 1, 0,_y, 
						0, 0, 1,_z, 
						0, 0, 0, 1);
}

inline Matrix4x4 TranslationMatrix(const Vec3f& _position)
{
	return Matrix4x4(	1, 0, 0, _position.x,
						0, 1, 0, _position.y,
						0, 0, 1, _position.z,
						0, 0, 0, 1);
}

inline Matrix4x4 RotationMatrix(float _x = 0.f, float _y = 0.f, float _z = 0.f)
{
	Matrix4x4 matX(			1,			0,			0,			0,
							0,	  cos(_x),   -sin(_x),			0,
							0,	  sin(_x),    cos(_x),			0,
							0,			0,			0,			1);

	Matrix4x4 matY(	  cos(_y),			0,	  sin(_y),			0,
							0,			1,			0,			0,
					 -sin(_y),			0,	  cos(_y),			0,
							0,			0,			0,			1);

	Matrix4x4 matZ(	  cos(_z),   -sin(_z),			0,			0,
					  sin(_z),    cos(_z),			0,			0,
							0,			0,			1,			0,
							0,			0,			0,			1);

	matX = (matY * matX * matZ);
	return matX;
}

inline Matrix4x4 RotationMatrix(const Quat& _quat)
{
	float _0 = (_quat.scalar * _quat.scalar) + (_quat.i * _quat.i) - (_quat.j * _quat.j) - (_quat.k * _quat.k);
	float _1 = (2 * _quat.i * _quat.j) - (2 * _quat.scalar * _quat.k);
	float _2 = (2 * _quat.scalar * _quat.j) + (2 * _quat.i * _quat.k);
	float _3 = 0;
	float _4 = (2 * _quat.scalar * _quat.k) + (2 * _quat.i * _quat.j);
	float _5 = (_quat.scalar * _quat.scalar) - (_quat.i * _quat.i) + (_quat.j * _quat.j) - (_quat.k * _quat.k);
	float _6 = (2 * _quat.j * _quat.k) - (2 * _quat.scalar * _quat.i);
	float _7 = 0;
	float _8 = (2 * _quat.i * _quat.k) - (2 * _quat.scalar * _quat.j);
	float _9 = (2 * _quat.scalar * _quat.i) + (2 * _quat.j * _quat.k);
	float _10 = (_quat.scalar * _quat.scalar) - (_quat.i * _quat.i) - (_quat.j * _quat.j) + (_quat.k * _quat.k);
	float _11 = 0;
	float _12 = 0;
	float _13 = 0;
	float _14 = 0;
	float _15 = 1;

	return Matrix4x4(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15);
}

inline Matrix4x4 RotationMatrix(const Vec3f& _rotation)
{
	Matrix4x4 matX(	1,	0,					0,					0,
					0,	cos(_rotation.x),	-sin(_rotation.x),	0,
					0,	sin(_rotation.x),	cos(_rotation.x),	0,
					0,	0,					0,					1);

	Matrix4x4 matY(	cos(_rotation.y),	0,	sin(_rotation.y),	0,
					0,					1,	0,					0,
					-sin(_rotation.y),	0,	cos(_rotation.y),	0,
					0,					0,	0,					1);

	Matrix4x4 matZ(	cos(_rotation.z),	-sin(_rotation.z),	0,	0,
					sin(_rotation.z),	cos(_rotation.z),	0,	0,
					0,					0,					1,	0,
					0,					0,					0,	1);

	matX = (matY * matX * matZ);
	return matX;
}

inline Matrix4x4 ScaleMatrix(float _x = 0.f, float _y = 0.f, float _z = 0.f)
{
	return Matrix4x4(  _x, 0, 0, 0,
						0,_y, 0, 0,
						0, 0,_z, 0,
						0, 0, 0, 1);
}

inline Matrix4x4 ScaleMatrix(const Vec3f& _scale)
{
	return Matrix4x4(	_scale.x,	0,			0,			0,
						0,			_scale.y,	0,			0,
						0,			0,			_scale.z,	0,
						0,			0,			0,			1);
}

} // namespace math
} // namespace pad