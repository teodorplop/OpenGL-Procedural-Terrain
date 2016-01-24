#pragma once

#include <unordered_map>
#include "../Utils/Math/Vector2.h"
#include "Window.h"

class Input {
private:
	static GLFWwindow* window;

	static Vector2 scroll;
	static Vector2 mousePosition;
	static Vector2 mouseMovement;

	static void ScrollCallback(GLFWwindow* window, double xOffSet, double yOffSet);
	static void CursorPositionCallback(GLFWwindow* window, double x, double y);

public:
	static void HandleInput(Window* window);
	static void Update();

	static bool GetKey(int key);
	static bool GetMouseButton(int button);
	static Vector2 GetScroll();
	static Vector2 GetMousePosition();
	static Vector2 GetMouseMovement();
};