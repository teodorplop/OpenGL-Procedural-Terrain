#pragma once
class HeightMapGenerator {
public:
	static void Generate(const char* filename, int width, int height);

private:
	static float** GenerateWhiteNoise(int width, int height);
	static float** GenerateSmoothNoise(float** whiteNoise, int width, int height, int octave);
	static float Interpolate(float a, float b, float alpha);
};
