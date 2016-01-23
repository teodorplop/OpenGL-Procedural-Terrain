#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../Scene.h"
#include "Window.h"

class Engine {
private:
	static Engine* instance;
	Engine(int argc, char** argv);
	Scene* currentScene;
	Window* currentWindow;

public:
	static void Start(int argc, char** argv);
};