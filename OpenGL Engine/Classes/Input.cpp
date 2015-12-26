#include "Input.h"
#include <GL\freeglut.h>
#include<cstdio>
#include<iostream>

Input* Input::instance = nullptr;

Input::Input() {
	glutMouseFunc(HandleMouse);
	glutMotionFunc(HandleMotion);
	glutPassiveMotionFunc(HandlePassiveMotion);

	glutKeyboardFunc(HandleKeyboard);
	glutKeyboardUpFunc(HandleKeyboardUp);
}

Input::~Input() {
}

void Input::Start() {
	if (instance == nullptr) {
		instance = new Input();
	}
}

void Input::Update() {
	instance->UpdateHandler();
}

void Input::UpdateHandler() {
	mouseButtonIsDown.clear();
	mouseButtonIsUp.clear();
	keyIsDown.clear();
	keyIsUp.clear();
}

void Input::HandleMotion(int x, int y) {
	instance->MotionHandler(x, y);
}
void Input::HandlePassiveMotion(int x, int y) {
	instance->PassiveMotionHandler(x, y);
}
void Input::HandleMouse(int button, int state, int x, int y) {
	instance->MouseHandler(button, state, x, y);
}
void Input::HandleKeyboard(unsigned char key, int x, int y) {
	instance->KeyboardHandler(key, x, y);
}
void Input::HandleKeyboardUp(unsigned char key, int x, int y) {
	instance->KeyboardUpHandler(key, x, y);
}

void Input::MotionHandler(int x, int y) {
	mousePosition = Vector3((float)x, (float)y);
}
void Input::PassiveMotionHandler(int x, int y) {
	mousePosition = Vector3((float)x, (float)y);
}
void Input::MouseHandler(int button, int state, int x, int y) {
	if (state == 0) {
		mouseButtonIs[button] = mouseButtonIsDown[button] = true;
	} else {
		mouseButtonIs[button] = false;
		mouseButtonIsUp[button] = true;
	}
}
void Input::KeyboardHandler(unsigned char key, int x, int y) {
	if (!keyIs[key]) {
		keyIsDown[key] = true;
		keyIs[key] = true;
	}
}
void Input::KeyboardUpHandler(unsigned char key, int x, int y) {
	keyIsUp[key] = true;
	keyIs[key] = false;
}

bool Input::GetKey(unsigned char key) {
	return instance->keyIs[key];
}
bool Input::GetKeyDown(unsigned char key) {
	return instance->keyIsDown[key];
}
bool Input::GetKeyUp(unsigned char key) {
	return instance->keyIsUp[key];
}
bool Input::GetMouseButton(int button) {
	return instance->mouseButtonIs[button];
}
bool Input::GetMouseButtonDown(int button) {
	return instance->mouseButtonIsDown[button];
}
bool Input::GetMouseButtonUp(int button) {
	return instance->mouseButtonIsUp[button];
}
Vector3 Input::GetMousePosition() {
	return instance->mousePosition;
}