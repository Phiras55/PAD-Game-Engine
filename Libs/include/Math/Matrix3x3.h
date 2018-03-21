#pragma once
#include <Math/Vector3.h>

namespace pad	{
namespace math	{

struct Matrix3x3 final																				/*! 4x4 Matrix of float structure */
{
#pragma region Constructor / Destructor

	Matrix3x3();																					/*!< Default constructor: create a unit matrix */
	Matrix3x3(float _00, float _01, float _02,														/*!< Constructor with values (16 floats) */
			  float _10, float _11, float _12,											
			  float _20, float _21, float _22);							
	Matrix3x3(const float*	_data);																	/*!< Constructor with data array (float) */
	Matrix3x3(Matrix3x3&	_matrix);																/*!< Copy constructor */
	
	Matrix3x3(Matrix3x3&&	_matrix)	= default;													/*!< Default move constructor */

	~Matrix3x3()						= default;													/*!< Default destructor */

#pragma endregion

#pragma region Variables

	float data[9];																					/*!< Data (by array of float) */

#pragma endregion

#pragma region Member Functions

	bool IsIdentity();																				/*!< Return true if the matrix is  */
	bool IsOrthogonal();																			/*!< Return true if the matrix is  */
	Matrix3x3&	Transpose();																		/*!< Return reference of the transposed matrix */
	Matrix3x3	Transposed();																		/*!< Return a transposed copy of the matrix */																	

#pragma endregion


#pragma region Operator

	float*		operator[]	(const	int			_index);											/*!< Access operator */
	void		operator=	(const	Matrix3x3&	_matrix);											/*!< Assignement operator */
	Matrix3x3&	operator=	(		Matrix3x3&&	_matrix) = default;									/*!< Default move operator */
	bool		operator==	(const	Matrix3x3&	_matrix);											/*!< Equal operator */
	bool		operator!=	(const	Matrix3x3&	_matrix);											/*!< Not equal operator */
	Matrix3x3	operator+	(const	Matrix3x3&	_matrix);											/*! Arithmetic operator: Addition*/
	Matrix3x3&	operator+=	(const	Matrix3x3&	_matrix);											/*! Compound assignment: Addition */
	Matrix3x3	operator-	(const	Matrix3x3&	_matrix);											/*! Arithmetic operator: Substraction */
	Matrix3x3&	operator-=	(const	Matrix3x3&	_matrix);											/*! Compound assignment: Substraction */
	Matrix3x3	operator*	(const	Matrix3x3&	_matrix);											/*! Arithmetic operator: Multiplication */
	Matrix3x3&	operator*=	(const	Matrix3x3&	_matrix);											/*! Compound assignment: Multiplication */
	Vec3f		operator*	(const	Vec3f&		_vector);											/*! Arithmetic operator: Vector4<float> Multiplication */
	
#pragma endregion
};

std::ostream& operator<<(std::ostream& _out, const Matrix3x3& _matrix);								/*!< Ostream operator */

} // namespace math
} // namespace pad

#include <Math/Matrix3x3_impl.h>