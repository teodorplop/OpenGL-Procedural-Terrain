#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Engine {
	friend class TimeFrame;

private:
	static Engine* instance;
	static void Update();
	static void RenderFunction();
	static void CleanUpFunction();

	GLuint vboId, ColorBufferId;

	Engine(int argc, char** argv);
	void Render();
	void CleanUp();

public:
	static void Start(int argc, char** argv);
};