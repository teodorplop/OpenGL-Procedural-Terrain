#include "Engine.h"

#include "TimeFrame.h"
#include "ObjectManager.h"
#include "Renderer.h"
#include "Input.h"

Engine* Engine::instance = nullptr;

void Engine::Start(int argc, char** argv) {
	if (instance == nullptr) {
		instance = new Engine(argc, argv);
		glutMainLoop();
	}
}

Engine::Engine(int argc, char** argv) {
	glutInit(&argc, argv);
	currentWindow = new Window();

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fprintf(stderr, "Failed to initialize glew: %s\n", glewGetErrorString(error));
	}

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutDisplayFunc(RenderFunction);
	glutCloseFunc(CleanUpFunction);

	TimeFrame::Start();
	Input::Start();

	currentScene = new Scene();
}
Engine::~Engine() {
	glutDisplayFunc(NULL);
	glutCloseFunc(NULL);
}

void Engine::Update() {
	ObjectManager::GetInstance()->Update();
	Input::Update();

	glutPostRedisplay();
}

void Engine::RenderFunction() {
	instance->Render();
}

void Engine::CleanUpFunction() {
	instance->CleanUp();
}

void Engine::Render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Renderer::GetInstance()->Draw();

	glutSwapBuffers();
	glFlush();
}

void Engine::CleanUp() {
	ObjectManager::GetInstance()->CleanUp();
}