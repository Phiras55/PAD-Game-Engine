namespace pad	{
namespace math	{

#pragma region Utils

__m256 Setm256(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13)
{
	return _mm256_set_ps(	_13, _12, _11, _10,
							_03, _02, _01, _00);
}

#pragma endregion

#pragma region Constructor / Destructor
	
Matrix4x4::Matrix4x4()
{
	*__DATA256		= Setm256(	1, 0, 0, 0, 
								0, 1, 0, 0);
	*(__DATA256+1)	= Setm256(	0, 0, 1, 0, 
								0, 0, 0, 1);
}

Matrix4x4::Matrix4x4(	float _00, float _01, float _02, float _03, 
						float _10, float _11, float _12, float _13, 
						float _20, float _21, float _22, float _23, 
						float _30, float _31, float _32, float _33)
{
	*__DATA256			= Setm256(	_00, _01, _02, _03,  
									_10, _11, _12, _13);
	*(__DATA256 + 1)	= Setm256(	_20, _21, _22, _23,  
									_30, _31, _32, _33);
}

Matrix4x4::Matrix4x4(const float* _data)
{
	*__DATA256			= _mm256_load_ps(_data);
	*(__DATA256 + 1)	= _mm256_load_ps(_data + 8);
}

Matrix4x4::Matrix4x4(Matrix4x4& _matrix)
{
	*__DATA256 = *_matrix.__DATA256;
}



#pragma endregion

float* Matrix4x4::operator[](const int _index)
{
return data + _index*4;
}

void Matrix4x4::operator=(const Matrix4x4& _matrix)
{
	*__DATA256 = *_matrix.__DATA256;
}

bool Matrix4x4::operator==(const Matrix4x4& _matrix)
{
	__m256i mask = _mm256_castps_si256(_mm256_set1_ps(1.f));
	return (_mm256_test_all_zeros(	mask, _mm256_castps_si256( _mm256_xor_ps(__DATA256[0], _matrix.__DATA256[0]) )) == 1
									&&
			_mm256_test_all_zeros(	mask, _mm256_castps_si256( _mm256_xor_ps(__DATA256[1], _matrix.__DATA256[1]) )) == 1);
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& _matrix)
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

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& _matrix)
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

Matrix4x4 Matrix4x4::operator*(const Matrix4x4&	_matrix)
{
	Matrix4x4 mat(*this);
	mat *= _matrix;
	return mat;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& _matrix)
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

} // namespace math
} // namespace pad
