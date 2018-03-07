#pragma once

#include <iostream>

namespace pad	{
namespace math	{

template<typename T>
struct Vector2 final																/*! Templated vector 2 structure */
{
#pragma region Constructor / Destructor

	Vector2();																		/*!< Default constructor */
	Vector2(const T _x, const T _y);												/*!< Constructor by value */

	template<typename U>
	Vector2(const Vector2<U>& _vector);												/*!< Constructor by copy */
	
	Vector2(Vector2&& _vector)	= default;											/*!< Move constructor */
	~Vector2()					= default;											/*!< Default destructor */

#pragma endregion

#pragma region Variables

	T x;																			/*!< X axis value of the vector */
	T y;																			/*!< Y axis value of the vector */

#pragma endregion

#pragma region Member Functions

	float		DotProduct(const Vector2& _vector) const;							/*!< Returns the dot product between the current vector and the vector passed as argument */
	float		Length() const;														/*!< Returns the length (or magnitude) of the vector */
	Vector2&	Normalize();														/*!< Normalize the vector itself and returns it */
	Vector2		Normalized() const;													/*!< Returns a normalized copy of the vector, without affecting the vector itself */
	bool		IsNull() const;														/*!< Returns true if the length of the vector is equal to 0 */
	bool		IsUnit() const;														/*!< Returns true if the length of the vector is equal to 1 */

#pragma endregion

#pragma region Operator

	void		operator=	(const	Vector2&	_vector);							/*! Assignment operator*/
	Vector2&	operator=	(		Vector2&&	_vector)	= default;				/*! Move assignment operator */
	bool		operator==	(const	Vector2&	_vector);							/*! Equal to operator */
	bool		operator!=	(const	Vector2&	_vector);							/*! Not equal to operator */
	Vector2		operator+	(const	Vector2&	_vector);							/*! Arithmetic operator: addition */
	Vector2&	operator+=	(const	Vector2&	_vector);							/*! Compound assignment: addition */
	Vector2		operator-	(const	Vector2&	_vector);							/*! Arithmetic operator: substraction */
	Vector2&	operator-=	(const	Vector2&	_vector);							/*! Compound assignment: substraction */
	Vector2		operator*	(const	float		_scalar);							/*! Arithmetic operator: multiplication */
	Vector2&	operator*=	(const	float		_scalar);							/*! Compound assignment: multiplication */
	Vector2		operator/	(const	float		_scalar);							/*! Arithmetic operator: division */
	Vector2&	operator/=	(const	float		_scalar);							/*! Compound assignment: division */

#pragma endregion
};

#pragma region Utils

template <typename T>																/*! << operator to print vector value with std::cout */
std::ostream& operator<<(std::ostream& _out, const Vector2<T>& _vector);

#pragma endregion

} // namespace math
} // namespace pad

#include <Math/Vector2_impl.h>