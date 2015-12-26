#include "Engine.h"

#include "TimeFrame.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Scene.h"

Engine* Engine::instance = nullptr;

void Engine::Start(int argc, char** argv) {
	if (instance == nullptr) {
		instance = new Engine(argc, argv);
		glutMainLoop();
	}
}

Engine::Engine(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(900, 600);
	glutCreateWindow("Sistem solar");

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fprintf(stderr, "Failed to initialize glew: %s\n", glewGetErrorString(error));
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutDisplayFunc(RenderFunction);
	glutMouseFunc(MouseFunction);
	glutKeyboardFunc(KeyboardFunction);
	glutCloseFunc(CleanUpFunction);

	ObjectManager::Start();
	TimeFrame::Start();
	InputManager::Start();

	Scene* scene = new Scene();
}

void Engine::Update() {
	ObjectManager::Update();

	glutPostRedisplay();
}

void Engine::RenderFunction() {
	instance->Render();
}

void Engine::MouseFunction(int button, int state, int x, int y) {
	InputManager::HandleMouse(button, state, x, y);
}
void Engine::KeyboardFunction(unsigned char key, int x, int y) {
	InputManager::HandleKeyboard(key, x, y);
}

void Engine::CleanUpFunction() {
	instance->CleanUp();
}

void Engine::Render() {
	glClear(GL_COLOR_BUFFER_BIT);

	ObjectManager::Draw();

	glutSwapBuffers();
	glFlush();
}

void Engine::CleanUp() {
	ObjectManager::CleanUp();
}