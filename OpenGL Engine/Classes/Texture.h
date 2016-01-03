#pragma once

#include <string>
#include <GL\glew.h>
#include <GL\freeglut.h>

class Texture {
private:
	std::string fileName;
	GLuint textureID;
	GLsizei width, height;

public:
	Texture(const std::string& fileName);
	~Texture();

	void Bind();
	void Unbind();
};
