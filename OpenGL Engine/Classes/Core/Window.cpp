#include "Window.h"
#include <GL\freeglut.h>
#include <cstdio>

Window* Window::instance = NULL;

Window::Window(const char* title, int width, int height) {
	instance = this;

	this->title = title, this->width = width, this->height = height;

	if (!Init()) {
		glfwTerminate();
	}
}

Window::~Window() {
	glfwTerminate();
}

bool Window::Init() {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW!");
		return false;
	}

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to create GLFW window!");
		return false;
	}
	
	int screenWidth, screenHeight;
	screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	int windowPosX, windowPosY;
	windowPosX = screenWidth / 2 - width / 2;
	windowPosY = screenHeight / 2 - height / 2;
	glfwSetWindowPos(window, windowPosX, windowPosY);

	glfwMakeContextCurrent(window);
	return true;
}

void Window::Update() {
	glfwPollEvents();
	glfwSwapBuffers(window);
}

bool Window::Closed() {
	return glfwWindowShouldClose(window);
}

GLFWwindow* Window::GetGLFWWindow() {
	return window;
}

int Window::GetWidth() {
	return width;
}
int Window::GetHeight() {
	return height;
}

Window* Window::GetWindow() {
	return instance;
}