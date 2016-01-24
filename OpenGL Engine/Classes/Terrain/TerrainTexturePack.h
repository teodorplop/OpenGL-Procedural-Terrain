#pragma once

#include "../Texture.h"

class TerrainTexturePack {
private:
	Texture* backgroundTexture;
	Texture* rTexture;
	Texture* gTexture;
	Texture* bTexture;

public:
	TerrainTexturePack(Texture* backgroundTexture, Texture* rTexture, Texture* gTexture, Texture* bTexture);

	Texture* GetBackgroundTexture();
	Texture* GetRTexture();
	Texture* GetGTexture();
	Texture* GetBTexture();
};

