#pragma once

#include<GL\freeglut.h>

class ImageUtils {
public:
	static BYTE* Load_Image(const char* fileName, GLsizei* width, GLsizei* height);
};