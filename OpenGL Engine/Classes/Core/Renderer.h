#pragma once

#include "../RawModel.h"
#include "../TexturedModel.h"

class Renderer {
public:
	static void Draw(RawModel* model);
	static void Draw(TexturedModel* texturedModel);
};
