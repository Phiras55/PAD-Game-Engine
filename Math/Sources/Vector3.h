#pragma once

#include <iostream>

namespace pad	{
namespace math	{

template<typename T>
struct Vector3 final
{
#pragma region Constructor / Destructor

	Vector3();

	Vector3(const T _x, const T _y, const T _z);
	template<typename U>
	Vector3(const Vector3<U>& _vector);

	Vector3(Vector3&& _vector)	= default;
	~Vector3()					= default;

#pragma endregion

#pragma region Variables

	union {	T x; 
			T r; };

	union {	T y;
			T g; };

	union {	T z;
			T b; };

#pragma endregion

#pragma region Member Functions

	float	DotProduct(const Vector3& _vector) const;
	float	Length() const;
	void	Normalize();
	Vector3	Normalized();
	bool	IsNull() const;
	bool	IsUnit() const;

#pragma endregion

#pragma region Operator

	void		operator=	(const	Vector3&	_vector);
	Vector3&	operator=	(		Vector3&&	_vector)	= default;
	bool		operator==	(const	Vector3&	_vector);
	Vector3		operator+	(const	Vector3&	_vector);
	Vector3&	operator+=	(const	Vector3&	_vector);
	Vector3		operator-	(const	Vector3&	_vector);
	Vector3&	operator-=	(const	Vector3&	_vector);
	Vector3		operator*	(const	float		_scalar);
	Vector3&	operator*=	(const	float		_scalar);
	Vector3		operator/	(const	float		_scalar);
	Vector3&	operator/=	(const	float		_scalar);


#pragma endregion
};

#pragma region Utils

template <typename T>
std::ostream& operator<<(std::ostream& _out, const Vector3<T>& _vector);

#pragma endregion

} // namespace math
} // namespace pad

#include <Vector3_impl.h>
