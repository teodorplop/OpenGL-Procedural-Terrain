#pragma once

#include "../RawModel.h"
#include "../Texture.h"
#include "TerrainTexturePack.h"
#include "../Utils/Math/Matrix4.h"
#include "../Utils/ImageUtils.h"

class Terrain {
private:
	static float size;
	static float maxHeight;
	static float maxPixelColor;

	Matrix4 worldMatrix;
	RawModel* model;
	TerrainTexturePack* texturePack;
	Texture* blendMap;

	void GenerateModel(const char* heightMap);
	void CalculateHeights(float** heights, const int& cells, FIBITMAP* data);
	Vector3 CalculateNormal(const int& x, const int& y, float** heights, const int& cells);
	float GetHeight(FIBITMAP* data, const int& x, const int& y);

public:
	Terrain(int gridX, int gridZ, TerrainTexturePack* texture, Texture* blendMap, const char* heightMap);
	~Terrain();

	const Matrix4& GetWorldMatrix() const;
	RawModel* GetModel();
	TerrainTexturePack* GetTexturePack();
	Texture* GetBlendMap();
};
