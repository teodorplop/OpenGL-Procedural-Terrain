#include "HeightMapGenerator.h"
#include "../Utils/Random.h"
#include "../Utils/ImageUtils.h"
#include "../Utils/Math/math_3d.h"

const std::string HeightMapGenerator::heightMapPath = "Textures/Terrain/HeightMaps/";

void HeightMapGenerator::Generate(const char* filename, int width, int height) {
	int octaves = 7;
	float **whiteNoise = GenerateWhiteNoise(width, height);
	float ***smoothNoises = new float**[octaves];

	for (int octave = 0; octave < octaves; ++octave) {
		smoothNoises[octave] = GenerateSmoothNoise(whiteNoise, width, height, octave);
	}

	float **perlinNoise = new float*[width];
	for (int i = 0; i < width; ++i) {
		perlinNoise[i] = new float[height];
		for (int j = 0; j < height; ++j) {
			perlinNoise[i][j] = 0.0f;
		}
	}
	float amplitude = 1.0f;
	float totalAmplitude = 0.0f;

	for (int octave = octaves - 1; octave >= 0; --octave) {
		amplitude /= 2.0f;
		totalAmplitude += amplitude;

		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				perlinNoise[i][j] += smoothNoises[octave][i][j] * amplitude;
			}
		}
	}

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			perlinNoise[i][j] /= totalAmplitude;
		}
	}

	SaveHeightMap(perlinNoise, width, height, std::string(filename) + ".png");

	for (int ii = 0; ii < octaves; ++ii) {
		perlinNoise = smoothNoises[ii];

		std::string temp = filename;
		temp += std::to_string(ii);
		temp += ".png";
		SaveHeightMap(perlinNoise, width, height, temp);
	}
}

float** HeightMapGenerator::GenerateWhiteNoise(int width, int height) {
	Random::SetSeed(0);

	float** whiteNoise = new float*[width];
	for (int i = 0; i < width; ++i) {
		whiteNoise[i] = new float[height];
		for (int j = 0; j < height; ++j) {
			whiteNoise[i][j] = Random::Next();
		}
	}

	return whiteNoise;
}

float** HeightMapGenerator::GenerateSmoothNoise(float** whiteNoise, int width, int height, int octave) {
	int delta = 1 << octave;
	float frequency = 1.0f / delta;

	float** smoothNoise = new float*[width];
	for (int i = 0; i < width; ++i) {
		smoothNoise[i] = new float[height];

		int i0 = (i / delta) * delta;
		int i1 = (i0 + delta) % width;
		float horizontalBlend = (i - i0) * frequency;

		for (int j = 0; j < height; ++j) {
			int j0 = (j / delta) * delta;
			int j1 = (j0 + delta) % height;
			float verticalBlend = (j - j0) * frequency;

			float top = Interpolate(whiteNoise[i0][j0], whiteNoise[i1][j0], horizontalBlend);
			float bottom = Interpolate(whiteNoise[i0][j1], whiteNoise[i1][j1], horizontalBlend);

			smoothNoise[i][j] = Interpolate(top, bottom, verticalBlend);
		}
	}

	return smoothNoise;
}

float HeightMapGenerator::Interpolate(float a, float b, float factor) {
	float alpha = factor * M_PI;
	factor = (1.0f - cos(alpha)) / 2.0f;
	return a * (1.0f - factor) + b * factor;
}

void HeightMapGenerator::SaveHeightMap(float** perlinNoise, int width, int height, std::string filename) {
	FIBITMAP* bitmap = FreeImage_Allocate(width, height, 32);
	RGBQUAD color;

	int maxValue = 1 << 24;
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			int value = (int)(perlinNoise[i][j] * maxValue);
			color.rgbBlue = value % (1 << 8);
			value /= (1 << 8);
			color.rgbGreen = value % (1 << 8);
			value /= (1 << 8);
			color.rgbRed = value % (1 << 8);

			FreeImage_SetPixelColor(bitmap, i, j, &color);
		}
	}

	filename = heightMapPath + filename;
	FreeImage_Save(FIF_PNG, bitmap, filename.c_str(), 0);
}