#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class OpenGL {
private:
	static OpenGL* instance;
	static void renderFunction();
	static void idleFunction();
	static void cleanUpFunction();

	double lastUpdate;
	GLuint VaoId, VboId, ColorBufferId;

	OpenGL(int argc, char** argv);
	void render();
	void idle();
	void cleanUp();

	void createVBO();
	void destroyVBO();

	void createShaders();
	void destroyShaders();

public:
	static void Initialize(int argc, char** argv);
};