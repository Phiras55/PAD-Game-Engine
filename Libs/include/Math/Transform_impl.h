namespace pad	{
namespace math	{

void Transform::ComputeLocalMatrix()
{
	localTransform =		TranslationMatrix(position)
						*	RotationMatrix()
						*	ScaleMatrix();

	isDirty = false;
}

const Mat4& Transform::GetLocalTransform()
{
	if (isDirty)
		ComputeLocalMatrix();

	return localTransform;
}

void Transform::SetGlobalTransform(const Mat4& _globalTransform)
{
	globalTransform = _globalTransform;
}

void Transform::SetPosition(const Vec3f& _position)
{
	position	= _position;
	isDirty		= true;
}

void Transform::Move(const Vec3f& _movement)
{
	position	+= _movement;
	isDirty		= true;
}

void Transform::SetRotation(const Vec3f& _rotation)
{
	rotation	= _rotation;
	isDirty		= true;
}

void Transform::SetScale(const Vec3f& _scale)
{
	scale		= _scale;
	isDirty		= true;
}

void Transform::SetScale(const float _scalar)
{
	scale		= Vec3f(_scalar, _scalar, _scalar);
	isDirty		= true;
}

void Transform::ScaleBy(const float _scalar)
{
	scale		*= _scalar;
	isDirty		= true;
}

} // namespace math
} // namespace pad