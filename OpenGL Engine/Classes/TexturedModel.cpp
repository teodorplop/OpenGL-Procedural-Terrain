#include "TexturedModel.h"

TexturedModel::TexturedModel(RawModel* model, Texture* texture) {
	this->model = model, this->texture = texture;
}

TexturedModel::~TexturedModel() {
}

RawModel* TexturedModel::GetModel() {
	return model;
}
Texture* TexturedModel::GetTexture() {
	return texture;
}