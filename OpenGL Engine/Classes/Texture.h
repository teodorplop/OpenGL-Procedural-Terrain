#pragma once

#include <string>
#include <GL\glew.h>
#include <GL\freeglut.h>

class Texture {
private:
	std::string fileName;
	GLuint textureID;
	GLsizei width, height;
	bool hasTransparency;

public:
	Texture(const std::string& fileName, bool hasTransparency = false);
	~Texture();

	bool HasTransparency();

	void Bind(int index = 0);
	void Unbind();
};
