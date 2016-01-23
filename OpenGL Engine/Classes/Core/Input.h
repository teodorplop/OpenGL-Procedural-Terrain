#pragma once

#include <unordered_map>
#include "../Utils/Math/Vector3.h"
#include "Window.h"

class Input {
private:
	static Input* instance;
	GLFWwindow* window;

public:
	static void HandleInput(Window* window);

	Input(Window* window);
	~Input();

	static bool GetKey(int key);
	static bool GetMouseButton(int button);
	static Vector3 GetMousePosition();
};