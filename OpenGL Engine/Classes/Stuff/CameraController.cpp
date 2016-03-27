#include "CameraController.h"

#include <GLFW\glfw3.h>

#include "../Camera.h"
#include "../Core/Input.h"

CameraController::CameraController(Transform* camera) {
	this->camera = camera;
}

void CameraController::Update() {
	Vector3 translation;
	if (Input::GetKey(GLFW_KEY_W)) {
		translation += Vector3(0.0f, 0.0f, 2.0f);
	}
	if (Input::GetKey(GLFW_KEY_S)) {
		translation -= Vector3(0.0f, 0.0f, 2.0f);
	}
	if (Input::GetKey(GLFW_KEY_A)) {
		translation -= Vector3(2.0f, 0.0f, 0.0f);
	}
	if (Input::GetKey(GLFW_KEY_D)) {
		translation += Vector3(2.0f, 0.0f, 0.0f);
	}
	if (Input::GetMouseButton(0)) {
		camera->RotateBy(Input::GetMouseMovement().x * 0.05f, Vector3(0.0f, 1.0f));
	}
	if (Input::GetMouseButton(1)) {
		translation += Vector3(0.0f, Input::GetMouseMovement().y * 0.05f);
	}
	if (Input::GetKey(GLFW_KEY_1)) {
		camera->RotateBy(1.0f, Vector3(1.0f, 0.0f));
	}
	if (Input::GetKey(GLFW_KEY_2)) {
		camera->RotateBy(-1.0f, Vector3(1.0f, 0.0f));
	}
	camera->TranslateBy(translation);
}
