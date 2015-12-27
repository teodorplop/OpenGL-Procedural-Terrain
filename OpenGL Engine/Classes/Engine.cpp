#include "Engine.h"

#include "TimeFrame.h"
#include "ComponentManager.h"
#include "Renderer.h"
#include "Input.h"
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
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Sistem solar");

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fprintf(stderr, "Failed to initialize glew: %s\n", glewGetErrorString(error));
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutDisplayFunc(RenderFunction);
	glutCloseFunc(CleanUpFunction);

	ComponentManager::Start();
	Renderer::Start();
	TimeFrame::Start();
	Input::Start();

	Scene* scene = new Scene();
}
Engine::~Engine() {
	glutDisplayFunc(NULL);
	glutCloseFunc(NULL);
}

void Engine::Update() {
	Input::Update();
	ComponentManager::Update();

	glutPostRedisplay();
}

void Engine::RenderFunction() {
	instance->Render();
}

void Engine::CleanUpFunction() {
	instance->CleanUp();
}

void Engine::Render() {
	glClear(GL_COLOR_BUFFER_BIT);

	Renderer::Draw();

	glutSwapBuffers();
	glFlush();
}

void Engine::CleanUp() {
	ComponentManager::CleanUp();
}