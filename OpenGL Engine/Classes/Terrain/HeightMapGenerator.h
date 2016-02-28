#pragma once

#include <string>

class HeightMapGenerator {
private:
	static const std::string heightMapPath;

public:
	static void Generate(const char* filename, int width, int height);

private:
	static float** GenerateWhiteNoise(int width, int height);
	static float** GenerateSmoothNoise(float** whiteNoise, int width, int height, int octave);
	static float Interpolate(float a, float b, float alpha);
	static void SaveHeightMap(float** perlinNoise, int width, int height, std::string filename);
};
