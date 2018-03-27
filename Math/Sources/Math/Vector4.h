#pragma once

#include <iostream>
#include <Math/Vector3.h>
#include <immintrin.h>

namespace pad	{
namespace math	{

template<typename T>
struct Vector4 final																				/*! Templated vector 4 structure */
{
#pragma region Constructor / Destructor

	Vector4();																						/*!< Default constructor */
	Vector4(const T _x, const T _y, const T _z, const T _w);										/*!< Constructor by value */

	template<typename U>
	Vector4(const Vector4<U>& _vector);																/*!< Constructor by copy */
	Vector4(const Vector4& _vector);																/*!< Constructor by copy */
	template<typename U>
	Vector4(const Vector3<U>& _vector);																/*!< Constructor by vector3 */
	Vector4(const Vector3<T>& _vector);																/*!< Constructor by vector3 */

	Vector4(Vector4&& _vector)	= default;															/*!< Move constructor */
	~Vector4()					= default;															/*!< Default destructor */

#pragma endregion

#pragma region Variables
	union {
		struct {	T x;																			/*!< X axis value of the vector */
					T y;																			/*!< Y axis value of the vector */
					T z;																			/*!< Z axis value of the vector */
					T w;																			/*!< W value of the vector */
				};
		struct {	T r;																			/*!< Red channel value of the color */
					T g;																			/*!< Green channel value of the color */
					T b;																			/*!< Blue channel value of the color */
					T a;																			/*!< Alpha channel value of the color */
				};
		__m128 __DATA128;																			/*!< Data values as __m128 for SSE instructions*/
	};

#pragma endregion

#pragma region Member Functions

	Vector4	CrossProduct(const Vector4& _vector) const;												/*!< Returns the cross product of the current vector and the vector passed as argument */
	float	DotProduct(const Vector4& _vector) const;												/*!< Returns the dot product of the current vector and the vector passed as argument */
	float	Length() const;																			/*!< Returns the length (or magnitude) of the vector */
	void	Normalize();																			/*!< Normalize the vector itself and returns it */
	Vector4	Normalized();																			/*!< Returns a normalized copy of the vector, without affecting the vector itself */
	bool	IsNull() const;																			/*!< Returns true if the length of the vector is equal to 0 */
	bool	IsUnit() const;																			/*!< Returns true if the length of the vector is equal to 1 */

#pragma endregion

#pragma region Operator

	template <typename U>
	void		operator=	(const	Vector4<U>&	_vector);											/*! Assignment operator*/
	void		operator=	(const	Vector4&	_vector);											/*! Assignment operator*/
	Vector4&	operator=	(		Vector4&&	_vector)	= default;								/*! Move assignment operator */
	bool		operator==	(const	Vector4&	_vector);											/*! Equal to operator */
	bool		operator!=	(const	Vector4&	_vector);											/*! Not equal to operator */
	Vector4		operator+	(const	Vector4&	_vector);											/*! Arithmetic operator: addition */
	Vector4&	operator+=	(const	Vector4&	_vector);											/*! Compound assignment: addition */
	Vector4		operator-	(const	Vector4&	_vector);											/*! Arithmetic operator: substraction */
	Vector4&	operator-=	(const	Vector4&	_vector);											/*! Compound assignment: substraction */
	Vector4		operator*	(const	float		_scalar);											/*! Arithmetic operator: multiplication */
	Vector4&	operator*=	(const	float		_scalar);											/*! Compound assignment: multiplication */
	Vector4		operator/	(const	float		_scalar);											/*! Arithmetic operator: division */
	Vector4&	operator/=	(const	float		_scalar);											/*! Compound assignment: division */
	T&			operator[]	(const	int			_index);											/*! Access operator */
	const T&	operator[]	(const	int			_index) const;										/*! Access operator */


#pragma endregion
};

#pragma region Utils

template <typename T>																				/*! << operator to print vector value with std::cout */
std::ostream& operator<<(std::ostream& _out, const Vector4<T>& _vector);		

template <typename T>
T DotProduct(Vector4<T> _v1, Vector4<T> _v2);

template <typename T>
Vector4<T> CrossProduct(Vector4<T> _v1, Vector4<T> _v2);

#pragma endregion

} // namespace math
} // namespace pad

#include <Math/Vector4_impl.h>