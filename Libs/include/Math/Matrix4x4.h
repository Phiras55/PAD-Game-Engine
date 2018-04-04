#pragma once
#include <Math/Vector4.h>
#include <immintrin.h>
#include <emmintrin.h>

namespace pad	{
namespace math	{

struct Matrix4x4 final																				/*! 4x4 Matrix of float structure */
{
#pragma region Constructor / Destructor

	inline Matrix4x4();																				/*!< Default constructor: create a unit matrix */
	inline Matrix4x4(	float _00, float _01, float _02, float _03,									/*!< Constructor with values (16 floats) */
						float _10, float _11, float _12, float _13,											
						float _20, float _21, float _22, float _23,
						float _30, float _31, float _32, float _33 );							
	inline Matrix4x4(const float* _data);															/*!< Constructor with data array (float) */
	inline Matrix4x4(const Matrix4x4& _matrix);														/*!< Copy constructor */
	
	inline Matrix4x4(Matrix4x4&& _matrix)	= default;												/*!< Default move constructor */
	
	inline ~Matrix4x4()						= default;													/*!< Default destructor */

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

	inline bool IsIdentity();																		/*!< Return true if the matrix is  */
	inline bool IsOrthogonal();																		/*!< Return true if the matrix is  */
	inline Matrix4x4&	Transpose();																/*!< Return reference of the transposed matrix */
	inline Matrix4x4	Transposed();																/*!< Return a transposed copy of the matrix */

#pragma endregion


#pragma region Operator

	inline float*		operator[]	(const	int			_index);									/*!< Access operator */
	inline const float*	operator[]	(const	int			_index) const;								/*!< Const Access operator */
	inline void			operator=	(const	Matrix4x4&	_matrix);									/*!< Assignement operator */
	inline Matrix4x4&	operator=	(		Matrix4x4&&	_matrix) = default;							/*!< Default move operator */
	inline bool			operator==	(const	Matrix4x4&	_matrix) const;								/*!< Compare operator */
	inline bool			operator!=	(const	Matrix4x4&	_matrix) const;								/*!< Not equal operator */
	inline Matrix4x4	operator+	(const	Matrix4x4&	_matrix) const;								/*! Arithmetic operator: Addition*/
	inline Matrix4x4&	operator+=	(const	Matrix4x4&	_matrix);									/*! Compound assignment: Addition */
	inline Matrix4x4	operator-	(const	Matrix4x4&	_matrix) const;								/*! Arithmetic operator: Substraction */
	inline Matrix4x4&	operator-=	(const	Matrix4x4&	_matrix);									/*! Compound assignment: Substraction */
	inline Matrix4x4	operator*	(const	Matrix4x4&	_matrix) const;								/*! Arithmetic operator: Multiplication */
	inline Matrix4x4&	operator*=	(const	Matrix4x4&	_matrix);									/*! Compound assignment: Multiplication */
	inline Vec4f		operator*	(const	Vec4f&		_vector) const;									/*! Arithmetic operator: Vector4<float> Multiplication */

#pragma endregion
};

inline std::ostream& operator<<(std::ostream& _out, const Matrix4x4& _matrix);						/*!< Ostream operator */

} // namespace math
} // namespace pad

#include <Math/Matrix4x4_impl.h>