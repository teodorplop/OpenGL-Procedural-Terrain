#pragma once

#include <GLFW\glfw3.h>

class Window {
private:
	static Window* instance;

	const char* title;
	int width, height;
	GLFWwindow* window;

	bool Init();

public:
	Window(const char* title, int width, int height);
	~Window();
	void Update();
	bool Closed();

	GLFWwindow* GetGLFWWindow();
	int GetWidth();
	int GetHeight();

	static Window* GetWindow();
};

