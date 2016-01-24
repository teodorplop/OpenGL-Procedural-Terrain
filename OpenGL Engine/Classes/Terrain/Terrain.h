#pragma once

#include "../RawModel.h"
#include "../Texture.h"
#include "TerrainTexturePack.h"
#include "../Utils/Math/Matrix4.h"

class Terrain {
private:
	static float size;
	static int cells;

	Matrix4 worldMatrix;
	RawModel* model;
	TerrainTexturePack* texturePack;
	Texture* blendMap;

	void GenerateModel();

public:
	Terrain(int gridX, int gridZ, TerrainTexturePack* texture, Texture* blendMap);
	~Terrain();

	const Matrix4& GetWorldMatrix() const;
	RawModel* GetModel();
	TerrainTexturePack* GetTexturePack();
	Texture* GetBlendMap();
};
