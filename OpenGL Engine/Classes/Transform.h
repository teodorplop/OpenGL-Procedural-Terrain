#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include <vector>
#include <unordered_set>
#include "Utils\Math\math_3d.h"

class Transform {
private:
	Transform* parent;
	std::unordered_set<Transform*> children;

	Vector3 localPosition, localRotation, localScale;
	Matrix4 localMatrix;

	Matrix4 matrix;

	void AddChild(Transform* child);
	void RemoveChild(Transform* child);
	void Refresh();

public:
	Transform();
	~Transform();
	void SetParent(Transform* other);

	Vector3 GetLocalPosition();
	Vector3 GetLocalRotation();
	Vector3 GetLocalScale();
	Matrix4 GetMatrix();

	void TranslateTo(const Vector3& position);
	void ScaleTo(const Vector3& scale);
	void RotateTo(float angle, const Vector3& axis);

	void TranslateBy(const Vector3& distance);
	void ScaleBy(const Vector3& scale);
	void RotateBy(float angle, const Vector3& axis);

	void RotateAroundBy(const Vector3& point, const Vector3& axis, float angle);
};

#endif // __TRANSFORM_H__