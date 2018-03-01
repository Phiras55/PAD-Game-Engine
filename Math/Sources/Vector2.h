#pragma once

#include <iostream>

namespace pad	{
namespace math	{

/*! Templated vector 2 structure*/
template<typename T>
struct Vector2 final
{
#pragma region Constructor / Destructor

	Vector2();
	Vector2(const T _x, const T _y);

	template <typename U>
	Vector2(const Vector2<U>& _vector);
	
	Vector2(Vector2&& _vector)	= default;
	~Vector2()					= default;

#pragma endregion

#pragma region Variables

	T x;
	T y;

#pragma endregion

#pragma region Member Functions

	float		DotProduct(const Vector2& _vector) const;
	float		Length() const;
	Vector2&	Normalize();													/*!< Normalize the vector itself and returns it */
	Vector2		Normalized() const;												/*!< Return a normalized copy of the vector, without affecting the vector itself */
	bool		IsNull() const;
	bool		IsUnit() const;

#pragma endregion

#pragma region Operator

	void		operator=	(const	Vector2&	_vector);
	Vector2&	operator=	(		Vector2&&	_vector)	= default;
	bool		operator==	(const	Vector2&	_vector);
	Vector2		operator+	(const	Vector2&	_vector);
	Vector2&	operator+=	(const	Vector2&	_vector);
	Vector2		operator-	(const	Vector2&	_vector);
	Vector2&	operator-=	(const	Vector2&	_vector);
	Vector2		operator*	(const	float		_scalar);
	Vector2&	operator*=	(const	float		_scalar);
	Vector2		operator/	(const	float		_scalar);
	Vector2&	operator/=	(const	float		_scalar);


#pragma endregion
};

#pragma region Utils

template <typename T>
std::ostream& operator<<(std::ostream& _out, const Vector2<T>& _vector);

#pragma endregion

} // namespace math
} // namespace pad

#include <Vector2_impl.h>