#include "Matrix3x3.h"
namespace pad	{
namespace math	{

using Mat3 = Matrix3x3;

#pragma region Constructor / Destructor	

Matrix3x3::Matrix3x3()
{
	data[0] = 0;	data[1] = 0;	data[2] = 0;
	data[3] = 0;	data[4] = 0;	data[5] = 0;
	data[6] = 0;	data[7] = 0;	data[8] = 0;
}

Matrix3x3::Matrix3x3(	float _00, float _01, float _02, 
						float _10, float _11, float _12, 
						float _20, float _21, float _22)
{
	data[0] = _00;	data[1] = _01;	data[2] = _02;
	data[3] = _10;	data[4] = _11;	data[5] = _12;
	data[6] = _20;	data[7] = _21;	data[8] = _22;
}

Matrix3x3::Matrix3x3(const float* _data)
{
	memcpy(data, _data, 9);
}

Matrix3x3::Matrix3x3(Matrix3x3& _matrix)
{
	memcpy(data, _matrix.data, 9);
}

#pragma endregion

bool Matrix3x3::IsIdentity()
{
	return (Matrix3x3() == *this);
}

bool Matrix3x3::IsOrthogonal()
{
	Matrix3x3 T(*this);
	T.Transpose();
	Matrix3x3 mat = (*this) * T;

	return (mat.IsIdentity());
}

Matrix3x3& Matrix3x3::Transpose()
{
	Matrix3x3 _mat(*this);
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			data[y*3+x] = _mat.data[x*3+y];
	return _mat;
}

Matrix3x3 Matrix3x3::Transposed()
{
	return Matrix3x3(*this).Transpose();
}

float* Matrix3x3::operator[](const int _index)
{
	return data+_index*3;
}

void Matrix3x3::operator=(const Matrix3x3& _matrix)
{
	memcpy(data, _matrix.data, 9);
}

bool Matrix3x3::operator==(const Matrix3x3& _matrix)
{
	if (memcmp(data, _matrix.data, 9) == 0)	return true;
	else									return false;
}

bool Matrix3x3::operator!=(const Matrix3x3& _matrix)
{
return (data[0] != _matrix.data[0] || data[1] != _matrix.data[1] || data[2] != _matrix.data[2] || 
		data[3] != _matrix.data[3] || data[4] != _matrix.data[4] || data[5] != _matrix.data[5] || 
		data[6] != _matrix.data[6] || data[7] != _matrix.data[7] || data[8] != _matrix.data[8]);
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& _matrix)
{
	Matrix3x3 mat(*this);
	mat += _matrix;
	return mat;
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& _matrix)
{
	data[0] += _matrix.data[0]; data[1] += _matrix.data[1]; data[2] += _matrix.data[2];
	data[3] += _matrix.data[3]; data[4] += _matrix.data[4]; data[5] += _matrix.data[5];
	data[6] += _matrix.data[6]; data[7] += _matrix.data[7]; data[8] += _matrix.data[8];
	return *this;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& _matrix)
{
	Matrix3x3 mat(*this);
	mat -= _matrix;
	return mat;
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& _matrix)
{
	data[0] -= _matrix.data[0]; data[1] -= _matrix.data[1]; data[2] -= _matrix.data[2];
	data[3] -= _matrix.data[3]; data[4] -= _matrix.data[4]; data[5] -= _matrix.data[5];
	data[6] -= _matrix.data[6]; data[7] -= _matrix.data[7]; data[8] -= _matrix.data[8];
	return *this;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3&	_matrix)
{
	Matrix3x3 mat(*this);
	mat *= _matrix;
	return mat;
}

Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& _matrix)
{
	for (char y = 0; y < 3; ++y)
	{
		for (char x = 0; x < 3; ++x)
		{
					float*	 mData	= &data[(y*3)+x];
			const	float*	_mData	= &_matrix.data[x];
			*mData = (	*mData * *(_mData	) +
						*mData * *(_mData +3) +
						*mData * *(_mData +6));
		}
	}
	return *this;
}

Vec3f Matrix3x3::operator*(const Vec3f& _vector)
{
	Vec3f vec;
	vec.x = data[0] * _vector.x + data[1] * _vector.y + data[2] * _vector.z;
	vec.y = data[3] * _vector.x + data[4] * _vector.y + data[5] * _vector.z;
	vec.z = data[6] * _vector.x + data[7] * _vector.y + data[8] * _vector.z;
	return vec;
}

std::ostream& operator<<(std::ostream& _out, const Matrix3x3 & _matrix)
{
return _out
<<"["<<_matrix.data[0]<<", "<<_matrix.data[1]<<", "<<_matrix.data[2]<<"]"<<std::endl
<<"["<<_matrix.data[3]<<", "<<_matrix.data[4]<<", "<<_matrix.data[5]<<"]"<<std::endl
<<"["<<_matrix.data[6]<<", "<<_matrix.data[7]<<", "<<_matrix.data[8]<<"]"<<std::endl;
}

} // namespace math
} // namespace pad
