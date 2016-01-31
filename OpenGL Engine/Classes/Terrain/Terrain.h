#pragma once

#include "../RawModel.h"
#include "../Texture.h"
#include "TerrainTexturePack.h"
#include "../Utils/Math/Matrix4.h"
#include "../Utils/ImageUtils.h"

class Terrain {
public:
	static const float size;
private:
	static const float maxHeight;
	static const float maxPixelColor;

	float x, z;
	Matrix4 worldMatrix;
	RawModel* model;
	TerrainTexturePack* texturePack;
	Texture* blendMap;

	int cells;
	float** heights;

	void GenerateModel(const char* heightMap);
	void CalculateHeights(FIBITMAP* data);
	Vector3 CalculateNormal(const int& x, const int& y);
	float GetHeight(FIBITMAP* data, const int& x, const int& y);

public:
	Terrain(int gridX, int gridZ, TerrainTexturePack* texture, Texture* blendMap, const char* heightMap);
	~Terrain();

	float GetTerrainHeight(const float& worldX, const float& worldZ);

	const Matrix4& GetWorldMatrix() const;
	RawModel* GetModel();
	TerrainTexturePack* GetTexturePack();
	Texture* GetBlendMap();
};
