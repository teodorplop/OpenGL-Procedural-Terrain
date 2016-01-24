#include "TerrainTexturePack.h"

TerrainTexturePack::TerrainTexturePack(Texture* backgroundTexture, Texture* rTexture, Texture* gTexture, Texture* bTexture) {
	this->backgroundTexture = backgroundTexture;
	this->rTexture = rTexture;
	this->gTexture = gTexture;
	this->bTexture = bTexture;
}

Texture* TerrainTexturePack::GetBackgroundTexture() {
	return backgroundTexture;
}
Texture* TerrainTexturePack::GetRTexture() {
	return rTexture;
}
Texture* TerrainTexturePack::GetGTexture() {
	return gTexture;
}
Texture* TerrainTexturePack::GetBTexture() {
	return bTexture;
}