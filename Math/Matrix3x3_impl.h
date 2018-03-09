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
	*data = *_data;
}

Matrix3x3::Matrix3x3(Matrix3x3& _matrix)
{
	*data = *_matrix.data;
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
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			data[y*4+x] = _mat.data[x*4+y];
}

Matrix3x3 Matrix3x3::Transposed()
{
	return Matrix3x3(*this).Transpose();
}

float* Matrix3x3::operator[](const int _index)
{
	return data+_index*4;
}

void Matrix3x3::operator=(const Matrix3x3& _matrix)
{
	*__DATA256		= *_matrix.__DATA256;
	*(__DATA256+1)	= *(_matrix.__DATA256+1);
}

bool Matrix3x3::operator==(const Matrix3x3& _matrix)
{
	__m256i mask = _mm256_castps_si256(_mm256_set1_ps(1.f));
	return (_mm256_test_all_zeros(	mask, 
		_mm256_castps_si256( _mm256_xor_ps(__DATA256[0], _matrix.__DATA256[0]) )) == 1
									&&
			_mm256_test_all_zeros(	mask, 
		_mm256_castps_si256( _mm256_xor_ps(__DATA256[1], _matrix.__DATA256[1]) )) == 1);
}

bool Matrix3x3::operator!=(const Matrix3x3 & _matrix)
{
	return (!(*this == _matrix));
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& _matrix)
{
	Matrix3x3 mat(*this);
	mat += _matrix;
	return mat;
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& _matrix)
{
	__DATA256[0] = _mm256_add_ps(__DATA256[0], _matrix.__DATA256[0]);
	__DATA256[1] = _mm256_add_ps(__DATA256[1], _matrix.__DATA256[1]);
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
	__DATA256[0] = _mm256_sub_ps(__DATA256[0], _matrix.__DATA256[0]);
	__DATA256[1] = _mm256_sub_ps(__DATA256[1], _matrix.__DATA256[1]);
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
	for (char y = 0; y < 4; ++y)
	{
		for (char x = 0; x < 4; ++x)
		{
					float*	mData	= &data[(y*4)+x];
			const	float*	_mData	= &_matrix.data[x];
			*mData = (	*mData * *(_mData) +
						*mData * *(_mData +4) +
						*mData * *(_mData +8) +
						*mData * *(_mData +12));
		}
	}
	return *this;
}

Vec4f Matrix3x3::operator*(const Vec4f& _vector)
{
	Vec4f vec;
	for (char i = 0; i < 4; i++)
	{
		__m128 temp = _mm_mul_ps(__DATA128[i], _vector.__DATA128);
		temp = _mm_hadd_ps(temp, temp);
		temp = _mm_hadd_ps(temp, temp);
		vec[i] = temp.m128_f32[0];
	}
	return vec;
}

std::ostream& operator<<(std::ostream & _out, const Matrix3x3 & _matrix)
{
return _out
<<"["<<_matrix.data[ 0]<<", "<<_matrix.data[ 1]<<", "<<_matrix.data[ 2]<<", "<<_matrix.data[ 3]<<"]"<<std::endl
<<"["<<_matrix.data[ 4]<<", "<<_matrix.data[ 5]<<", "<<_matrix.data[ 6]<<", "<<_matrix.data[ 7]<<"]"<<std::endl
<<"["<<_matrix.data[ 8]<<", "<<_matrix.data[ 9]<<", "<<_matrix.data[10]<<", "<<_matrix.data[11]<<"]"<<std::endl
<<"["<<_matrix.data[12]<<", "<<_matrix.data[13]<<", "<<_matrix.data[14]<<", "<<_matrix.data[15]<<"]"<<std::endl;
}

} // namespace math
} // namespace pad
