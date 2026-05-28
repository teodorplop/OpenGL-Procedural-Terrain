#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../Scene.h"
#include "Window.h"
#include "../Terrain/TerrainSettings.h"

class Engine {
private:
	static Engine* instance;
	Engine(int argc, char** argv);
	Scene* currentScene;
	Window* currentWindow;
	TerrainSettings* terrainSettings;

public:
	static void Start(int argc, char** argv);
	static Scene* CurrentScene();
};