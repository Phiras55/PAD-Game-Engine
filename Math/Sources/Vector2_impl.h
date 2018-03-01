namespace pad	{
namespace math	{

#pragma region Typedef

template<typename T>
using	Vec2	= Vector2<T>;
using	Vec2i	= Vector2<int>;
using	Vec2u	= Vector2<unsigned int>;
using	Vec2f	= Vector2<float>;
using	Vec2d	= Vector2<double>;

#pragma endregion

#pragma region Constructor / Destructor

template<typename T>
Vector2<T>::Vector2() :	
	x(0), 
	y(0) 
{
}

template<typename T>
template<typename U>
Vector2<T>::Vector2(const Vector2<U>& _vector) :
	x(_vector.x), 
	y(_vector.y)
{
}

template<typename T>
Vector2<T>::Vector2(const T _x, const T _y) :
	x(_x),
	y(_y)
{
}

#pragma endregion

#pragma region Member Functions

template<typename T>
float Vector2<T>::DotProduct(const Vector2& _vector) const
{
	return (x * _vector.x) + (y * _vector.y);
}

template<typename T>
float Vector2<T>::Length() const
{
	return sqrt((x * x) + (y * y));
}

template<typename T>
Vector2<T>& Vector2<T>::Normalize()
{
	if (!IsNull())
		return (*this /= Length());
}

template<typename T>
Vector2<T> Vector2<T>::Normalized() const
{
	if (!IsNull())
		return (*this / Length());
}

template<typename T>
bool Vector2<T>::IsNull() const
{
	return (x == 0 && y == 0);
}

template<typename T>
bool Vector2<T>::IsUnit() const
{
	return (Length == 1.f);
}

#pragma endregion

#pragma region Operator

template <typename T>
void Vector2<T>::operator=(const Vector2& _vector)
{
	x = _vector.x;
	y = _vector.y;
}

template <typename T>
bool Vector2<T>::operator==(const Vector2& _vector)
{
	return (x == _vector.x && y == _vector.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2& _vector)
{
	return Vector2<T>(x + _vector.x, y + _vector.y);
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2& _vector)
{
	x += _vector.x;
	y += _vector.y;
	return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2& _vector)
{
	return Vector2<T>(x - _vector.x, y - _vector.y);
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2& _vector)
{
	x -= _vector.x;
	y -= _vector.y;
	return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator*(const float _scalar)
{
	return Vector2<T>(x * _scalar, y * _scalar);
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(const float _scalar)
{
	x *= _scalar;
	y *= _scalar;
	return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator/(const float _scalar)
{
	return Vector2<T>(x / _scalar, y / _scalar);
}

template <typename T>
Vector2<T>& Vector2<T>::operator/=(const float _scalar)
{
	x /= _scalar;
	y /= _scalar;
	return *this;
}

#pragma endregion

#pragma region Utils

template <typename T>
std::ostream& operator<<(std::ostream& _out, const Vector2<T>& _vector)
{
	return _out << "(" << _vector.x << ", " << _vector.y << ")";
}

#pragma endregion

} // namespace math
} // namespace pad