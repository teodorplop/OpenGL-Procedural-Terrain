#include "Camera.h"
#include "Utils/Math/math_h.h"

Camera* Camera::mainCamera = NULL;

Camera* Camera::GetMainCamera() {
	return mainCamera;
}

Camera::Camera() {
	if (mainCamera == NULL) {
		mainCamera = this;
	}

	projectionType = Projection::Perspective;
	fieldOfView = 30.0f;
	aspectRatio = 1.5f;
	nearClip = 1.0f;
	farClip = 100.0f;
	projectionMatrix = Matrix4::Perspective(fieldOfView, aspectRatio, nearClip, farClip);

	/*projectionType = Projection::Orthographic;
	left = -1.0f;
	right = 1.0f;
	bottom = -1.0f;
	top = 1.0f;
	nearClip = 1.0f;
	farClip = 100.0f;
	projectionMatrix = Matrix4::Orthographic(left, right, bottom, top, nearClip, farClip);*/

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

void Camera::Zoom(float value) {
	if (projectionType == Projection::Perspective) {
		fieldOfView += value;
		fieldOfView = Clamp(fieldOfView, 5.0f, 180.0f);

		projectionMatrix = Matrix4::Perspective(fieldOfView, aspectRatio, nearClip, farClip);
	} else {

	}
}
void Camera::ZoomIn() {
	Zoom(-1.0f);
}
void Camera::ZoomOut() {
	Zoom(1.0f);
}