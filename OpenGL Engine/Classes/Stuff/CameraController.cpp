#include "CameraController.h"

#include <GLFW\glfw3.h>

#include "../Camera.h"
#include "../Core/Input.h"

CameraController::CameraController() {
}

CameraController::~CameraController() {
}

void CameraController::Update() {
	Vector3 translation;
	if (Input::GetKey(GLFW_KEY_W)) {
		translation += Vector3(0.0f, 0.0f, 0.01f);
	}
	if (Input::GetKey(GLFW_KEY_S)) {
		translation -= Vector3(0.0f, 0.0f, 0.01f);
	}
	if (Input::GetKey(GLFW_KEY_A)) {
		translation -= Vector3(0.01f, 0.0f, 0.0f);
	}
	if (Input::GetKey(GLFW_KEY_D)) {
		translation += Vector3(0.01f, 0.0f, 0.0f);
	}
	Camera::GetMainCamera()->GetTransform()->TranslateBy(translation);
}
