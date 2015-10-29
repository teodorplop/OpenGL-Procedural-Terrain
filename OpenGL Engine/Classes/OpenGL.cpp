#include "OpenGL.h"
#include "Shader.h"

#include <cstdio>
#include <cassert>
#include "Utils/Math/math_3d.h"

OpenGL* OpenGL::instance = nullptr;
float OpenGL::scale = 0;

void OpenGL::Initialize(int argc, char** argv) {
	if (instance != nullptr) {
		return;
	}

	instance = new OpenGL(argc, argv);
	glutMainLoop();
}

OpenGL::OpenGL(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Tutorial");

	glewInit();
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glutDisplayFunc(renderFunction);
	glutIdleFunc(renderFunction);
	glutCloseFunc(cleanUpFunction);
}

void OpenGL::renderFunction() {
	instance->render();
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

void OpenGL::cleanUp() {
	destroyVBO();
	destroyShaders();
}

void OpenGL::createVBO() {
	GLfloat Vertices[] = {
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f
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
	myShader->use();

	scale += 0.001f;
	Matrix4 matrix = Matrix4::Scale(Vector3(sin(scale), sin(scale), sin(scale)));

	GLint gWorld = glGetUniformLocation(myShader->getProgram(), "gWorld");

	glUniformMatrix4fv(gWorld, 1, GL_TRUE, &matrix.elements[0][0]);

	delete myShader;
}
void OpenGL::destroyShaders() {
}