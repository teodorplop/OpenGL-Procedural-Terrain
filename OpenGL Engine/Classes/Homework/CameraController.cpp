#include "CameraController.h"

#include "../Camera.h"
#include "../GameObject.h"
#include "../Input.h"

CameraController::CameraController() {
}

CameraController::~CameraController() {
}

void CameraController::Update() {
	Vector3 translation;
	if (Input::GetKey('w')) {
		translation += Vector3(0.0f, 0.05f, 0.0f);
	}
	if (Input::GetKey('s')) {
		translation -= Vector3(0.0f, 0.05f, 0.0f);
	}
	if (Input::GetKey('a')) {
		translation -= Vector3(0.05f, 0.0f, 0.0f);
	}
	if (Input::GetKey('d')) {
		translation += Vector3(0.05f, 0.0f, 0.0f);
	}
	gameObject->GetTransform()->TranslateBy(translation);

	if (Input::GetMouseButtonDown(0)) {
		mousePosition = Input::GetMousePosition();
	} else if (Input::GetMouseButton(0)) {
		Vector3 newMousePosition = Input::GetMousePosition();
		Vector3 direction = newMousePosition - mousePosition;

		if (direction != Vector3()) {
			direction.Normalize();

			gameObject->GetTransform()->RotateBy(0.5f * direction.x, Vector3(0.0f, 1.0f, 0.0f));
			gameObject->GetTransform()->RotateBy(0.5f * direction.y, Vector3(1.0f, 0.0f, 0.0f));
		}
	}
}
