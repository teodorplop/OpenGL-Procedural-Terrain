#include "Engine.h"

#include "TimeFrame.h"
#include "ObjectManager.h"
#include "Input.h"

Engine* Engine::instance = NULL;

Engine::Engine(int argc, char** argv) {
	glutInit(&argc, argv);

	currentWindow = new Window("OpenGL Terrain Engine", 1024, 768);

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fprintf(stderr, "Failed to initialize glew: %s\n", glewGetErrorString(error));
	}

	glEnable(GL_DEPTH_TEST);

	Input::HandleInput(currentWindow);
	currentScene = new Scene();

	while (!currentWindow->Closed()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// calls the update function for all objects
		ObjectManager::GetInstance()->Update();
		// clear the input
		Input::Update();

		// draws the models
		currentScene->Draw();

		TimeFrame::Update((float)glfwGetTime());

		currentWindow->Update();
	}
}

void Engine::Start(int argc, char** argv) {
	if (instance == NULL) {
		instance = new Engine(argc, argv);
	}
}