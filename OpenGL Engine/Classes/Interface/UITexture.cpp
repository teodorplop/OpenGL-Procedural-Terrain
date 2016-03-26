#include "UITexture.h"

UITexture::UITexture(Texture* texture) {
	RawModel* rawModel = RawModel::LoadQuad();
	TexturedModel* model = new TexturedModel(rawModel, texture);

	gameObject = new GameObject(model);
}

UITexture::~UITexture() {
}

GameObject* UITexture::GetGameObject() {
	return gameObject;
}