#include "Matrix4x4.h"
namespace pad	{
namespace math	{

using Mat4 = Matrix4x4;

#pragma region Constructor / Destructor	

Matrix4x4::Matrix4x4()
{
	*__DATA256		= _mm256_setr_ps(	1, 0, 0, 0,
										0, 1, 0, 0);
	*(__DATA256+1)	= _mm256_setr_ps(	0, 0, 1, 0,
										0, 0, 0, 1);
}

Matrix4x4::Matrix4x4(	float _00, float _01, float _02, float _03, 
						float _10, float _11, float _12, float _13, 
						float _20, float _21, float _22, float _23, 
						float _30, float _31, float _32, float _33)
{
	*__DATA256		= _mm256_setr_ps(	_00, _01, _02, _03,
										_10, _11, _12, _13);
	*(__DATA256+1)	= _mm256_setr_ps(	_20, _21, _22, _23,
										_30, _31, _32, _33);
}

Matrix4x4::Matrix4x4(const float* _data)
{
	*__DATA256		= _mm256_load_ps(_data);
	*(__DATA256+1)	= _mm256_load_ps(_data + 8);
}

Matrix4x4::Matrix4x4(const Matrix4x4& _matrix)
{
	*__DATA256		= *_matrix.__DATA256;
	*(__DATA256+1)	= *(_matrix.__DATA256+1);
}

#pragma endregion

bool Matrix4x4::IsIdentity()
{
	return (*this == Mat4());
}

bool Matrix4x4::IsOrthogonal()
{
	Matrix4x4 T(*this);
	T.Transpose();
	Matrix4x4 mat = (*this) * T;

	return (mat.IsIdentity());
}

Matrix4x4& Matrix4x4::Transpose()
{
	Matrix4x4 _mat(*this);
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			data[y*4+x] = _mat.data[x*4+y];
	return *this;
}

Matrix4x4 Matrix4x4::Transposed()
{
	return Matrix4x4(*this).Transpose();
}

float* Matrix4x4::operator[](const int _index)
{
	return data + _index * 4;
}

const float* Matrix4x4::operator[](const int _index) const
{
	return data + _index * 4;
}

void Matrix4x4::operator=(const Matrix4x4& _matrix)
{
	*__DATA256		= *_matrix.__DATA256;
	*(__DATA256+1)	= *(_matrix.__DATA256+1);
}

bool Matrix4x4::operator==(const Matrix4x4& _matrix) const
{
	__m256i mask = _mm256_set1_epi32(0xFFFFFFFF);
	return (_mm256_testz_si256(mask,
		_mm256_castps_si256( _mm256_xor_ps(__DATA256[0], _matrix.__DATA256[0]) ))
									&&
		_mm256_testz_si256(	mask,
		_mm256_castps_si256( _mm256_xor_ps(__DATA256[1], _matrix.__DATA256[1]) )));
}

bool Matrix4x4::operator!=(const Matrix4x4 & _matrix) const
{
	return (!(*this == _matrix));
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& _matrix) const
{
	Matrix4x4 mat(*this);
	mat += _matrix;
	return mat;
}

Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& _matrix)
{
	__DATA256[0] = _mm256_add_ps(__DATA256[0], _matrix.__DATA256[0]);
	__DATA256[1] = _mm256_add_ps(__DATA256[1], _matrix.__DATA256[1]);
	return *this;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& _matrix) const
{
	Matrix4x4 mat(*this);
	mat -= _matrix;
	return mat;
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& _matrix)
{
	__DATA256[0] = _mm256_sub_ps(__DATA256[0], _matrix.__DATA256[0]);
	__DATA256[1] = _mm256_sub_ps(__DATA256[1], _matrix.__DATA256[1]);
	return *this;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4&	_matrix) const
{
	Matrix4x4 mat(*this);
	mat *= _matrix;
	return mat;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& _matrix)
{
	Matrix4x4 temp(*this);
	for (char y = 0; y < 4; ++y)
	{
		for (char x = 0; x < 4; ++x)
		{
					float*	 mData	= &temp.data[y*4];
			const	float*	_mData	= &_matrix.data[x];
			data[y*4 + x] = (	*(mData  ) * *(_mData  ) +
								*(mData+1) * *(_mData+4) +
								*(mData+2) * *(_mData+8) +
								*(mData+3) * *(_mData+12));
		}
	}
	return *this;
}

Vec4f Matrix4x4::operator*(const Vec4f& _vector) const
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

std::ostream& operator<<(std::ostream& _out, const Matrix4x4& _matrix)
{
return _out<<
"["<<_matrix.data[ 0]<<", "<<_matrix.data[ 1]<<", "<<_matrix.data[ 2]<<", "<<_matrix.data[ 3]<<"]"<<std::endl<<
"["<<_matrix.data[ 4]<<", "<<_matrix.data[ 5]<<", "<<_matrix.data[ 6]<<", "<<_matrix.data[ 7]<<"]"<<std::endl<<
"["<<_matrix.data[ 8]<<", "<<_matrix.data[ 9]<<", "<<_matrix.data[10]<<", "<<_matrix.data[11]<<"]"<<std::endl<<
"["<<_matrix.data[12]<<", "<<_matrix.data[13]<<", "<<_matrix.data[14]<<", "<<_matrix.data[15]<<"]"<<std::endl;
}

} // namespace math
} // namespace pad
