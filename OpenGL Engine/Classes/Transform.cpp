#include "Transform.h"

Transform::Transform() {
	position = rotation = Vector3();
	scale = Vector3(1.0f, 1.0f, 1.0f);
	matrix = Matrix4(1.0f);
}

Transform::~Transform() {
}

void Transform::TranslateTo(const Vector3& position) {
	TranslateBy(position - this->position);
}

void Transform::ScaleTo(const Vector3& scale) {
	ScaleBy(scale / this->scale);
}

void Transform::RotateTo(float angle, const Vector3& axis) {
	this->rotation = axis * angle;
}

void Transform::TranslateBy(const Vector3& distance) {
	Matrix4::ApplyTranslation(matrix, distance);
	this->position += distance;
}

void Transform::ScaleBy(const Vector3& scale) {
	Matrix4::ApplyScaling(matrix, scale);
	this->scale *= scale;
}

void Transform::RotateBy(float angle, const Vector3& axis) {
	Matrix4::ApplyRotation(matrix, angle, axis);
	this->rotation += axis * angle;

	this->rotation.x = fmod(this->rotation.x, 360.0f);
	this->rotation.y = fmod(this->rotation.y, 360.0f);
	this->rotation.z = fmod(this->rotation.z, 360.0f);
}

void Transform::RotateAroundBy(const Vector3& point, const Vector3& axis, float angle) {
	Vector3 position = this->position;
	TranslateTo(point);
	RotateBy(angle, axis);
	TranslateTo(position);
}