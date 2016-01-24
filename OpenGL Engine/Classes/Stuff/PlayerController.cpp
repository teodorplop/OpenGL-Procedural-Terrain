#include "PlayerController.h"
#include "../Core/Input.h"
#include "../Core/TimeFrame.h"
#include "../Utils/Math/math_h.h"

float PlayerController::runSpeed = 20.0f;
float PlayerController::turnSpeed = 160.0f;
float PlayerController::gravity = -60.0f;
float PlayerController::jumpPower = 30.0f;

PlayerController::PlayerController(Transform* target) {
	this->target = target;
	this->currentSpeed = this->currentTurnSpeed = 0.0f, this->upwardsSpeed = 0.0f;
}

void PlayerController::Update() {
	if (Input::GetKey(GLFW_KEY_W)) {
		currentSpeed = runSpeed;
	} else if (Input::GetKey(GLFW_KEY_S)) {
		currentSpeed = -runSpeed;
	} else {
		currentSpeed = 0.0f;
	}
	if (Input::GetKey(GLFW_KEY_D)) {
		currentTurnSpeed = -turnSpeed;
	} else if (Input::GetKey(GLFW_KEY_A)) {
		currentTurnSpeed = turnSpeed;
	} else {
		currentTurnSpeed = 0.0f;
	}
	if (upwardsSpeed == 0.0f && Input::GetKey(GLFW_KEY_SPACE)) {
		upwardsSpeed = jumpPower;
	}

	target->RotateBy(currentTurnSpeed * TimeFrame::deltaTime, Vector3(0.0f, 1.0f, 0.0f));
	target->TranslateBy(Vector3(0.0f, 0.0f, currentSpeed * TimeFrame::deltaTime));

	upwardsSpeed += gravity * TimeFrame::deltaTime;
	Vector3 position = target->GetPosition();
	position.y += upwardsSpeed * TimeFrame::deltaTime;
	if (position.y < 0.0f) {
		upwardsSpeed = 0.0f;
		position.y = 0.0f;
	}

	target->TranslateTo(position);
}