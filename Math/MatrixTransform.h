#pragma once
#include <math.h>
#include <Math/Matrix4x4.h>

namespace pad {
namespace math {

Matrix4x4 TranslationMatrix(float _x= 0.f, float _y = 0.f, float _z = 0.f)
{
	return Matrix4x4(	1, 0, 0,_x,
						0, 1, 0,_y, 
						0, 0, 1,_z, 
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

	Matrix4x4 matZ(	  cos(_x),   -sin(_x),			0,			0,
					  sin(_x),    cos(_x),			0,			0,
							0,			0,			0,			0,
							0,			0,			0,			1);
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

}
}