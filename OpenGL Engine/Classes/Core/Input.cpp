#include "Input.h"
#include<cstdio>
#include<iostream>

Input* Input::instance = nullptr;

Input::Input(Window* window) {
	this->window = window->GetGLFWWindow();
}

Input::~Input() {
}

void Input::HandleInput(Window* window) {
	if (instance != NULL) {
		delete instance;
	}
	instance = new Input(window);
}

bool Input::GetKey(int key) {
	return glfwGetKey(instance->window, key) != 0;
}
bool Input::GetMouseButton(int button) {
	return glfwGetMouseButton(instance->window, button) != 0;
}
Vector3 Input::GetMousePosition() {
	double xPos, yPos;
	glfwGetCursorPos(instance->window, &xPos, &yPos);

	return Vector3((float)xPos, (float)yPos);
}