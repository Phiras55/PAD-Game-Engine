#pragma once

#include <iostream>

namespace pad	{
namespace math	{

template<typename T>
struct Vector3 final																				/*! Templated vector 3 structure */
{
#pragma region Constructor / Destructor

	Vector3();																						/*!< Default constructor */
	Vector3(const T _x, const T _y, const T _z);													/*!< Constructor by value */
	
	template<typename U>
	Vector3(const Vector3<U>& _vector);																/*!< Constructor by copy */
	Vector3(const Vector3& _vector);																/*!< Constructor by copy */

	Vector3(Vector3&& _vector)	= default;															/*!< Move constructor */
	~Vector3()					= default;															/*!< Default destructor */

#pragma endregion

#pragma region Variables		

	union {
		struct {	T x;																			/*!< X axis value of the vector */
					T y;																			/*!< Y axis value of the vector */
					T z;																			/*!< Z axis value of the vector */
				};
		struct {	T r;																			/*!< Red channel value of the color */
					T g;																			/*!< Green channel value of the color */
					T b;																			/*!< Blue channel value of the color */
				};
	};

#pragma endregion

#pragma region Member Functions

	Vector3	CrossProduct(const Vector3& _vector) const;												/*!< Returns the cross product of the current vector and the vector passed as argument */
	float	DotProduct(const Vector3& _vector) const;												/*!< Returns the dot product of the current vector and the vector passed as argument */
	float	Length() const;																			/*!< Returns the length (or magnitude) of the vector */
	void	Normalize();																			/*!< Normalize the vector itself and returns it */
	Vector3	Normalized();																			/*!< Returns a normalized copy of the vector, without affecting the vector itself */
	bool	IsNull() const;																			/*!< Returns true if the length of the vector is equal to 0 */
	bool	IsUnit() const;																			/*!< Returns true if the length of the vector is equal to 1 */

#pragma endregion

#pragma region Operator

	template <typename U>
	void		operator=	(const	Vector3<U>&	_vector);											/*! Assignment operator*/
	void		operator=	(const	Vector3&	_vector);											/*! Assignment operator*/
	Vector3&	operator=	(		Vector3&&	_vector)	= default;								/*! Move assignment operator */
	bool		operator==	(const	Vector3&	_vector) const;										/*! Equal to operator */
	bool		operator!=	(const	Vector3&	_vector);											/*! Not equal to operator */
	Vector3		operator+	(const	Vector3&	_vector) const;										/*! Arithmetic operator: addition */
	Vector3&	operator+=	(const	Vector3&	_vector);											/*! Compound assignment: addition */
	Vector3		operator-	(const	Vector3&	_vector) const;										/*! Arithmetic operator: substraction */
	Vector3&	operator-=	(const	Vector3&	_vector);											/*! Compound assignment: substraction */
	Vector3		operator*	(const	float		_scalar) const;										/*! Arithmetic operator: multiplication */
	Vector3&	operator*=	(const	float		_scalar);											/*! Compound assignment: multiplication */
	Vector3		operator/	(const	float		_scalar) const;										/*! Arithmetic operator: division */
	Vector3&	operator/=	(const	float		_scalar);											/*! Compound assignment: division */
	const T&	operator[]	(const	int			_index) const;										/*! Access operator */
	T&			operator[]	(const	int			_index);											/*! Access operator */

	Vector3		operator-	() const;

#pragma endregion
};

#pragma region Utils

template <typename T>																				/*! << operator to print vector value with std::cout */
std::ostream& operator<<(std::ostream& _out, const Vector3<T>& _vector);			

template <typename T>
T DotProduct(Vector3<T> _v1, Vector3<T> _v2);

template <typename T>
Vector3<T> CrossProduct(Vector3<T> _v1, Vector3<T> _v2);

#pragma endregion

} // namespace math
} // namespace pad

#include <Math/Vector3_impl.h>
