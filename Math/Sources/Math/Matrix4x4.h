#pragma once
#include <Math/Vector4.h>
#include <immintrin.h>
#include <emmintrin.h>

namespace pad	{
namespace math	{

struct Matrix4x4 final																				/*! 4x4 Matrix of float structure */
{
#pragma region Constructor / Destructor

	Matrix4x4();																					/*!< Default constructor: create a unit matrix */
	Matrix4x4(float _00, float _01, float _02, float _03,											/*!< Constructor with values (16 floats) */
			  float _10, float _11, float _12, float _13,											
			  float _20, float _21, float _22, float _23,
			  float _30, float _31, float _32, float _33 );							
	Matrix4x4(const float* _data);																	/*!< Constructor with data array (float) */
	Matrix4x4(Matrix4x4& _matrix);																	/*!< Copy constructor */
	
	Matrix4x4(Matrix4x4&& _matrix)	= default;														/*!< Default move constructor */
	
	~Matrix4x4()					= default;														/*!< Default destructor */

#pragma endregion

#pragma region Variables

	union
	{
		alignas(32) float data[16];																	/*!< Data (by array of float) */
		alignas(32) __m256 __DATA256[2];															/*!< Data (by two __m256) */
		alignas(16) __m128 __DATA128[4];															/*!< Data (by four __m128) */
	};

#pragma endregion

#pragma region Member Functions

	bool IsIdentity();																				/*!< Return true if the matrix is  */
	bool IsOrthogonal();																			/*!< Return true if the matrix is  */
	Matrix4x4&	Transpose();																		/*!< Return reference of the transposed matrix */
	Matrix4x4	Transposed();																		/*!< Return a transposed copy of the matrix */																	

#pragma endregion


#pragma region Operator

	float*		operator[]	(const	int			_index);											/*!< Access operator */
	void		operator=	(const	Matrix4x4&	_matrix);											/*!< Assignement operator */
	Matrix4x4&	operator=	(		Matrix4x4&&	_matrix) = default;									/*!< Default move operator */
	bool		operator==	(const	Matrix4x4&	_matrix);											/*!< Equal operator */
	bool		operator!=	(const	Matrix4x4&	_matrix);											/*!< Not equal operator */
	Matrix4x4	operator+	(const	Matrix4x4&	_matrix);											/*! Arithmetic operator: Addition*/
	Matrix4x4&	operator+=	(const	Matrix4x4&	_matrix);											/*! Compound assignment: Addition */
	Matrix4x4	operator-	(const	Matrix4x4&	_matrix);											/*! Arithmetic operator: Substraction */
	Matrix4x4&	operator-=	(const	Matrix4x4&	_matrix);											/*! Compound assignment: Substraction */
	Matrix4x4	operator*	(const	Matrix4x4&	_matrix);											/*! Arithmetic operator: Multiplication */
	Matrix4x4&	operator*=	(const	Matrix4x4&	_matrix);											/*! Compound assignment: Multiplication */
	Vec4f		operator*	(const	Vec4f&		_vector);											/*! Arithmetic operator: Vector4<float> Multiplication */

#pragma endregion
};

std::ostream& operator<<(std::ostream& _out, const Matrix4x4& _matrix);								/*!< Ostream operator */

} // namespace math
} // namespace pad

#include <Math/Matrix4x4_impl.h>