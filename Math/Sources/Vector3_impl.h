namespace pad	{
namespace math	{

#pragma region Typedef

template<typename T>
using	Vec3	= Vector3<T>;
using	Vec3i	= Vector3<int>;
using	Vec3u	= Vector3<unsigned int>;
using	Vec3f	= Vector3<float>;
using	Vec3d	= Vector3<double>;
using	Color3	= Vector3<unsigned char>;

#pragma endregion

#pragma region Constructor / Destructor

template<typename T>
Vector3<T>::Vector3() :	
	x(0), 
	y(0),
	z(0)
{
}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Vector3<U>& _vector) :
	x(_vector.x), 
	y(_vector.y),
	z(_vector.z)
{
}

template<typename T>
Vector3<T>::Vector3(const T _x, const T _y, const T _z) :
	x(_x),
	y(_y),
	z(_z)
{
}

#pragma endregion

#pragma region Member Functions

template<typename T>
Vector3<T> Vector3<T>::CrossProduct(const Vector3& _vector) const
{
	return Vector3<T>(	(y * _vector.z) - (z * _vector.y),
						(z * _vector.x) - (x * _vector.z),
						(x * _vector.y) - (y * _vector.x));
}

template<typename T>
float Vector3<T>::DotProduct(const Vector3& _vector) const
{
	return (x * _vector.x) + (y * _vector.y) + (z * _vector.z);
}

template<typename T>
float Vector3<T>::Length() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

template<typename T>
void Vector3<T>::Normalize()
{
	if (!IsNull())
		*this /= Length();
}

template<typename T>
Vector3<T> Vector3<T>::Normalized()
{
	if (!IsNull())
		return (*this / Length());
}

template<typename T>
bool Vector3<T>::IsNull() const
{
	return (x == 0 && y == 0 && z == 0);
}

template<typename T>
bool Vector3<T>::IsUnit() const
{
	return (Length == 1.f);
}

#pragma endregion

#pragma region Operator

template <typename T>
void Vector3<T>::operator=(const Vector3& _vector)
{
	x = _vector.x;
	y = _vector.y;
	z = _vector.z;
}

template <typename T>
bool Vector3<T>::operator==(const Vector3& _vector)
{
	return (	x == _vector.x 
			&&	y == _vector.y 
			&&	z == _vector.z);
}

template <typename T>
bool Vector3<T>::operator!=(const Vector3& _vector)
{
	return (	x != _vector.x
			||	y != _vector.y
			||	z != _vector.z);
}

template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3& _vector)
{
	return Vector3<T>(	x + _vector.x, 
						y + _vector.y,
						z + _vector.z);
}

template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3& _vector)
{
	x += _vector.x;
	y += _vector.y;
	z += _vector.z;
	return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3& _vector)
{
	return Vector3<T>(	x - _vector.x, 
						y - _vector.y,
						z - _vector.z);
}

template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3& _vector)
{
	x -= _vector.x;
	y -= _vector.y;
	z -= _vector.z;
	return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator*(const float _scalar)
{
	return Vector3<T>(	x * _scalar, 
						y * _scalar,
						z * _scalar);
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=(const float _scalar)
{
	x *= _scalar;
	y *= _scalar;
	z *= _scalar;
	return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator/(const float _scalar)
{
	if (_scalar != 0)
	{
		return Vector3<T>(	x / _scalar, 
							y / _scalar,
							z / _scalar);
	}
	else
		return NULL;
}

template <typename T>
Vector3<T>& Vector3<T>::operator/=(const float _scalar)
{
	if (_scalar != 0)
	{
		x /= _scalar;
		y /= _scalar;
		z /= _scalar;
		return *this;
	}
	else
		return NULL;
}

#pragma endregion

#pragma region Utils

template <typename T>
std::ostream& operator<<(std::ostream& _out, const Vector3<T>& _vector)
{
	return _out << "(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ")";
}

#pragma endregion

} // namespace math
} // namespace pad