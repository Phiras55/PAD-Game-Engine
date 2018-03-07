#pragma once
#include <immintrin.h>
#include <emmintrin.h>

namespace pad {
namespace math {

struct Matrix4x4 final
{
#pragma region Constructor / Destructor

	Matrix4x4();
	Matrix4x4(float _00, float _01, float _02, float _03,
			  float _10, float _11, float _12, float _13,
			  float _20, float _21, float _22, float _23,
			  float _30, float _31, float _32, float _33 );
	Matrix4x4(const float* _data);
	Matrix4x4(Matrix4x4& _matrix);
	
	Matrix4x4(Matrix4x4&& _matrix)	= default;
	
	~Matrix4x4()					= default;

#pragma endregion

#pragma region Variables

	union
	{
		alignas(32) float data[16];
		alignas(32) __m256 __DATA256[2];
		alignas(16) __m128 __DATA128[4];
	};

#pragma endregion

#pragma region Member Functions



#pragma endregion


#pragma region Operator

	float*		operator[]	(const	int			_index);
	void		operator=	(const	Matrix4x4&	_matrix);
	Matrix4x4&	operator=	(		Matrix4x4&&	_matrix) = default;
	bool		operator==	(const	Matrix4x4&	_matrix);
	Matrix4x4	operator+	(const	Matrix4x4&	_matrix);
	Matrix4x4&	operator+=	(const	Matrix4x4&	_matrix);
	Matrix4x4	operator-	(const	Matrix4x4&	_matrix);
	Matrix4x4&	operator-=	(const	Matrix4x4&	_matrix);
	Matrix4x4	operator*	(const	Matrix4x4&	_matrix);
	Matrix4x4&	operator*=	(const	Matrix4x4&	_matrix);
	Matrix4x4	operator*	(const	float&		_scalar);
	Matrix4x4&	operator*=	(const	float&		_scalar);

#pragma endregion
};

} // namespace math
} // namespace pad

#include <Matrix4x4_impl.h>