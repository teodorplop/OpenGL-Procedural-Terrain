#pragma once

#include <FreeImage.h>

class ImageUtils {
public:
	static BYTE* Load_Image(const char* fileName, int* width, int* height);
};
