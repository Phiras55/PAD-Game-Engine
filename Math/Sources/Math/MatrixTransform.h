#pragma once
#include <math.h>
#include <Math/Matrix4x4.h>

namespace pad	{
namespace math	{

Matrix4x4 TranslationMatrix(float _x= 0.f, float _y = 0.f, float _z = 0.f)
{
	return Matrix4x4(	1, 0, 0,_x,
						0, 1, 0,_y, 
						0, 0, 1,_z, 
						0, 0, 0, 1);
}

Matrix4x4 TranslationMatrix(const Vec3f& _position)
{
	return Matrix4x4(	1, 0, 0, _position.x,
						0, 1, 0, _position.y,
						0, 0, 1, _position.z,
						0, 0, 0, 1);
}

Matrix4x4 RotationMatrix(float _x = 0.f, float _y = 0.f, float _z = 0.f)
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
							0,			0,			0,			0,
							0,			0,			0,			1);
	matX *= (matY *= matZ);
	return matX;
}

Matrix4x4 RotationMatrix(const Vec3f& _rotation)
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
					0,					0,					0,	0,
					0,					0,					0,	1);
	matX *= (matY *= matZ);
	return matX;
}

Matrix4x4 ScaleMatrix(float _x = 0.f, float _y = 0.f, float _z = 0.f)
{
	return Matrix4x4(  _x, 0, 0, 0,
						0,_y, 0, 0,
						0, 0,_z, 0,
						0, 0, 0, 1);
}

Matrix4x4 ScaleMatrix(const Vec3f& _scale)
{
	return Matrix4x4(	_scale.x,	0,			0,			0,
						0,			_scale.y,	0,			0,
						0,			0,			_scale.z,	0,
						0,			0,			0,			1);
}

} // namespace math
} // namespace pad