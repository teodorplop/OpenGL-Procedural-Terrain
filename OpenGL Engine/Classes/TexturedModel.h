#pragma once

#include "RawModel.h"
#include "Texture.h"
#include "Materials\Material.h"

class TexturedModel {
private:
	RawModel* model;
	Texture* texture;

public:
	TexturedModel(RawModel* model, Texture* texture);
	~TexturedModel();
	RawModel* GetModel();
	Texture* GetTexture();
};
