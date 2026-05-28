#include "Input.h"
#include <cstdio>
#include <iostream>

GLFWwindow* Input::window = NULL;
Vector2 Input::scroll;
Vector2 Input::mousePosition;
Vector2 Input::mouseMovement;

void Input::HandleInput(Window* window) {
	if (Input::window != NULL) {
		glfwSetScrollCallback(Input::window, NULL);
	}

	Input::window = window->GetGLFWWindow();
	glfwSetScrollCallback(Input::window, ScrollCallback);
	glfwSetCursorPosCallback(Input::window, CursorPositionCallback);
}
void Input::Update() {
	scroll.x = scroll.y = 0.0f;
}

bool Input::GetKey(int key) {
	return glfwGetKey(window, key) != 0;
}
bool Input::GetMouseButton(int button) {
	return glfwGetMouseButton(window, button) != 0;
}
Vector2 Input::GetScroll() {
	return scroll;
}
Vector2 Input::GetMousePosition() {
	return mousePosition;
}
Vector2 Input::GetMouseMovement() {
	return mouseMovement;
}

void Input::ScrollCallback(GLFWwindow* window, double xOffSet, double yOffSet) {
	scroll.x = (float)xOffSet, scroll.y = (float)yOffSet;
}
void Input::CursorPositionCallback(GLFWwindow* window, double x, double y) {
	mouseMovement.x = (float)x - mousePosition.x;
	mouseMovement.y = (float)y - mousePosition.y;

	mousePosition.x = (float)x, mousePosition.y = (float)y;
}