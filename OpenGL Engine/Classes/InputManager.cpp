#include "InputManager.h"
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
}