#pragma once

#include <iostream>
#include <Vector3.h>

namespace pad	{
namespace math	{

template<typename T>
struct Vector4 final
{
#pragma region Constructor / Destructor

	Vector4();

	Vector4(const T _x, const T _y, const T _z, const T _w);
	Vector4(const Vector4& _vector);
	template<typename U>
	Vector4(const Vector3<U>& _vector);

	Vector4(Vector4&& _vector)	= default;
	~Vector4()					= default;

#pragma endregion

#pragma region Variables

	union {	T x; 
			T r; };

	union {	T y;
			T g; };

	union {	T z;
			T b; };

	union {	T w;
			T a; };

#pragma endregion

#pragma region Member Functions

	float	DotProduct(const Vector4& _vector) const;
	float	Length() const;
	void	Normalize();
	Vector4	Normalized();
	bool	IsNull() const;
	bool	IsUnit() const;

#pragma endregion

#pragma region Operator

	void		operator=	(const	Vector4&	_vector);
	Vector4&	operator=	(		Vector4&&	_vector)	= default;
	bool		operator==	(const	Vector4&	_vector);
	Vector4		operator+	(const	Vector4&	_vector);
	Vector4&	operator+=	(const	Vector4&	_vector);
	Vector4		operator-	(const	Vector4&	_vector);
	Vector4&	operator-=	(const	Vector4&	_vector);
	Vector4		operator*	(const	float		_scalar);
	Vector4&	operator*=	(const	float		_scalar);
	Vector4		operator/	(const	float		_scalar);
	Vector4&	operator/=	(const	float		_scalar);


#pragma endregion
};

#pragma region Utils

template <typename T>
std::ostream& operator<<(std::ostream& _out, const Vector4<T>& _vector);

#pragma endregion

} // namespace math
} // namespace pad

#include <Vector4_impl.h>