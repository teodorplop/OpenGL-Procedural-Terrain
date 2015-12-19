#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Scene.h"

class Engine {
	friend class TimeFrame;

private:
	static Engine* instance;
	static void Update();
	static void RenderFunction();
	static void MouseFunction(int button, int state, int x, int y);
	static void CleanUpFunction();

	Engine(int argc, char** argv);
	void Render();
	void Mouse(int button, int state, int x, int y);
	void CleanUp();

public:
	static void Start(int argc, char** argv);
};

#endif//__ENGINE_H__