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

	int mouseWheel = Input::GetMouseWheel();
	Camera* camera = (Camera*)gameObject->GetComponent("Camera");
	float fieldOfView = Clamp(camera->GetFieldOfView() + mouseWheel, 1.0f, 90.0f);
	camera->SetFieldOfView(fieldOfView);
}
