#include "Transform.h"

Transform::Transform() {
	parent = NULL;

	localPosition = localRotation = Vector3();
	localScale = Vector3(1.0f, 1.0f, 1.0f);
	localMatrix = matrix = Matrix4(1.0f);
}

Transform::~Transform() {
}

void Transform::SetParent(Transform* parent) {
	if (this->parent != NULL) {
		this->parent->RemoveChild(this);
	}

	this->parent = parent;

	localPosition = localRotation = Vector3();
	localScale = Vector3(1.0f, 1.0f, 1.0f);
	localMatrix = Matrix4(1.0f);

	this->parent->AddChild(this);
	Refresh();
}

void Transform::AddChild(Transform* child) {
	auto it = children.find(child);
	if (it == children.end()) {
		children.insert(child);
	}
}
void Transform::RemoveChild(Transform* child) {
	children.erase(child);
}
void Transform::Refresh() {
	if (parent != NULL) {
		matrix = parent->GetMatrix() * localMatrix;
	} else {
		matrix = localMatrix;
	}

	for (auto child : children) {
		child->Refresh();
	}
}

Vector3 Transform::GetLocalPosition() {
	return localPosition;
}
Vector3 Transform::GetLocalRotation() {
	return localRotation;
}
Vector3 Transform::GetLocalScale() {
	return localScale;
}
Matrix4 Transform::GetMatrix() {
	return matrix;
}

void Transform::TranslateTo(const Vector3& position) {
	TranslateBy(position - this->localPosition);
}

void Transform::ScaleTo(const Vector3& scale) {
	ScaleBy(scale / this->localScale);
}

void Transform::RotateTo(float angle, const Vector3& axis) {
	RotateBy(angle * axis.x, Vector3(1.0f, 0.0f, 0.0f));
	RotateBy(angle * axis.y, Vector3(0.0f, 1.0f, 0.0f));
	RotateBy(angle * axis.z, Vector3(0.0f, 0.0f, 1.0f));
}

void Transform::TranslateBy(const Vector3& distance) {
	Matrix4::ApplyTranslation(localMatrix, distance);
	this->localPosition += distance;

	Refresh();
}

void Transform::ScaleBy(const Vector3& scale) {
	Matrix4::ApplyScaling(localMatrix, scale);
	this->localScale *= scale;

	Refresh();
}

void Transform::RotateBy(float angle, const Vector3& axis) {
	Matrix4::ApplyRotation(localMatrix, angle, axis);
	this->localRotation += axis * angle;

	this->localRotation.x = fmod(this->localRotation.x, 360.0f);
	this->localRotation.y = fmod(this->localRotation.y, 360.0f);
	this->localRotation.z = fmod(this->localRotation.z, 360.0f);

	Refresh();
}

void Transform::RotateAroundBy(const Vector3& point, const Vector3& axis, float angle) {
	Vector3 position = this->localPosition;
	TranslateTo(point);
	RotateBy(angle, axis);
	TranslateTo(position);
}