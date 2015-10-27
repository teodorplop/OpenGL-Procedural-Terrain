#include "OpenGL.h"
#include "Shader.h"

#include <cstdio>

OpenGL* OpenGL::instance = nullptr;

void OpenGL::Initialize(int argc, char** argv) {
	if (instance != nullptr) {
		return;
	}

	instance = new OpenGL(argc, argv);
	glutMainLoop();
}

OpenGL::OpenGL(int argc, char** argv) {
	lastUpdate = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1200, 700);
	glutCreateWindow("Puncte & Segmente");

	glewInit();
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glutDisplayFunc(renderFunction);
	glutIdleFunc(idleFunction);
	glutCloseFunc(cleanUpFunction);
}

void OpenGL::renderFunction() {
	instance->render();
}

void OpenGL::idleFunction() {
	instance->idle();
}

void OpenGL::cleanUpFunction() {
	instance->cleanUp();
}

void OpenGL::render() {
	glClear(GL_COLOR_BUFFER_BIT);
	createVBO();
	createShaders();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glFlush();
}

void OpenGL::idle() {
	double now = glutGet(GLUT_ELAPSED_TIME);
	double timeElapsed = (now - lastUpdate) * 1000 / 60;

	while (timeElapsed >= 1000 / 60) {
		glutPostRedisplay();
		timeElapsed -= 1000 / 60;
	}

	lastUpdate = now;
}

void OpenGL::cleanUp() {
	destroyVBO();
	destroyShaders();
}

void OpenGL::createVBO() {
	float rnd = (float)(rand() % 5) / 10.0f;
	GLfloat Vertices[] = {
		0.0f, rnd, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f
	};
	GLfloat Colors[] = {
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f
	};

	// se creeaza un buffer nou
	glGenBuffers(1, &VboId);
	// este setat ca buffer curent
	glBindBuffer(GL_ARRAY_BUFFER, VboId);
	// punctele sunt "copiate" in bufferul curent
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// se activeaza lucrul cu atribute; atributul 0 = pozitie
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	// un nou buffer, pentru culoare
	glGenBuffers(1, &ColorBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, ColorBufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
	// atributul 1 =  culoare
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
}
void OpenGL::destroyVBO() {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &ColorBufferId);
	glDeleteBuffers(1, &VboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VaoId);
}

void OpenGL::createShaders() {
	Shader* myShader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	myShader->link();
	delete myShader;
}
void OpenGL::destroyShaders() {
}