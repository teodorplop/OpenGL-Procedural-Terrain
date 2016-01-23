#include "Window.h"
#include <GL\freeglut.h>

int Window::width = 1024;
int Window::height = 768;
char* Window::name = "OpenGL Terrain Engine";

Window::Window() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	int screenWidth, screenHeight;
	screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

	int screenPosX, screenPosY;
	screenPosX = screenWidth / 2 - width / 2;
	screenPosY = screenHeight / 2 - height / 2;

	glutInitWindowPosition(screenPosX, screenPosY);
	glutInitWindowSize(width, height);
	id = glutCreateWindow(name);
}

Window::~Window() {
	glutDestroyWindow(id);
}

int Window::WindowID() {
	return id;
}