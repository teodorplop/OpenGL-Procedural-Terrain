#include "Camera.h"
#include "Utils/Math/math_h.h"

Camera::Camera(Projection projection, float size, float aspect, float nearClip, float farClip) {
	projectionType = projection;
	if (projectionType == Projection::Orthographic) {
		SetOrthographic(size, aspect, nearClip, farClip);
	} else {
		SetPerspective(size, aspect, nearClip, farClip);
	}
	transform = new Transform();
}
Camera::~Camera() {
}

Projection Camera::GetProjectionType() {
	return projectionType;
}
Matrix4 Camera::GetProjectionMatrix() {
	return projectionMatrix;
}
Transform* Camera::GetTransform() {
	return transform;
}

void Camera::SetOrthographic(float orthographicSize, float aspectRatio, float nearClip, float farClip) {
	this->projectionType = Projection::Orthographic;
	this->orthographicSize = orthographicSize;
	this->aspectRatio = aspectRatio;
	this->nearClip = nearClip;
	this->farClip = farClip;
	
	float left, right, bottom, top;
	left = -orthographicSize * aspectRatio;
	right = orthographicSize * aspectRatio;
	bottom = -orthographicSize;
	top = orthographicSize;

	projectionMatrix = Matrix4::Orthographic(left, right, bottom, top, nearClip, farClip);
}
void Camera::SetPerspective(float fieldOfView, float aspectRatio, float nearClip, float farClip) {
	this->projectionType = Projection::Perspective;
	this->fieldOfView = fieldOfView;
	this->aspectRatio = aspectRatio;
	this->nearClip = nearClip;
	this->farClip = farClip;

	projectionMatrix = Matrix4::Perspective(fieldOfView, aspectRatio, nearClip, farClip);
}