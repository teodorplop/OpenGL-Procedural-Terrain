#pragma once

#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../Scene.h"
#include "../Window.h"

class Engine {
	friend class TimeFrame;

private:
	static Engine* instance;
	static void Update();
	static void RenderFunction();
	static void CleanUpFunction();

	Window* currentWindow;
	Scene* currentScene;
	Engine(int argc, char** argv);
	~Engine();
	void Render();
	void CleanUp();

public:
	static void Start(int argc, char** argv);
};