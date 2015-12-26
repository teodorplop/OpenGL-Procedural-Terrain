#include "InputManager.h"
#include "Camera.h"
#include<cstdio>

InputManager* InputManager::instance = nullptr;

InputManager::InputManager() {
}

InputManager::~InputManager() {
}

void InputManager::Start() {
	if (instance == nullptr) {
		instance = new InputManager();
	}
}

void InputManager::HandleMouse(int button, int state, int x, int y) {
	printf("HandleMouse: %d %d %d %d\n", button, state, x, y);
	switch (button) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		Camera::GetMainCamera()->ZoomIn();
		break;
	case 4:
		Camera::GetMainCamera()->ZoomOut();
		break;
	}
}
void InputManager::HandleKeyboard(unsigned char key, int x, int y) {
	printf("HandleKeyboard: %c %d %d\n", key, x, y);
	switch (key) {
	case 'w':
		Camera::GetMainCamera()->GetTransform()->TranslateBy(Vector3(0.0f, 0.05f, 0.0f));
		break;
	case 'a':
		Camera::GetMainCamera()->GetTransform()->TranslateBy(Vector3(-0.05f, 0.0f, 0.0f));
		break;
	case 's':
		Camera::GetMainCamera()->GetTransform()->TranslateBy(Vector3(0.00f, -0.05f, 0.0f));
		break;
	case 'd':
		Camera::GetMainCamera()->GetTransform()->TranslateBy(Vector3(0.05f, 0.0f, 0.0f));
		break;
	}
}