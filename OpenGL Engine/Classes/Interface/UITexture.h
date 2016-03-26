#pragma once

#include "../GameObject.h"
#include "../Texture.h"

class UITexture {
private:
	GameObject* gameObject;

public:
	UITexture(Texture* texture);
	~UITexture();

	GameObject* GetGameObject();
};