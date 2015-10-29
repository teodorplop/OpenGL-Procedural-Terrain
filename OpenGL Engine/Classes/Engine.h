#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Engine {
	friend class TimeFrame;

private:
	static Engine* instance;
	static void Update();
	static void renderFunction();
	static void cleanUpFunction();
	static float scale;

	GLuint VaoId, VboId, ColorBufferId;

	Engine(int argc, char** argv);
	void render();
	void cleanUp();

	void createVBO();
	void destroyVBO();

	void createShaders();
	void destroyShaders();

public:
	static void Initialize(int argc, char** argv);
};