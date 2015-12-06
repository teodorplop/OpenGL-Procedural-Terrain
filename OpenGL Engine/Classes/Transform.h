#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Utils\Math\math_3d.h"

class Transform {
public:
	Vector3 position, rotation, scale;
	Matrix4 matrix;

	Transform();
	~Transform();

	void TranslateTo(const Vector3& position);
	void ScaleTo(const Vector3& scale);
	void RotateTo(float angle, const Vector3& axis);

	void TranslateBy(const Vector3& distance);
	void ScaleBy(const Vector3& scale);
	void RotateBy(float angle, const Vector3& axis);
	void RotateAroundBy(const Vector3& point, const Vector3& axis, float angle);
};

#endif // __TRANSFORM_H__