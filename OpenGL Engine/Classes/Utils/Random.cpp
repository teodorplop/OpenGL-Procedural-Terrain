#include "Random.h"
#include <cstdlib>
#include <ctime>

int Random::Range(int left, int right) {
	return left + rand() % (right - left + 1);
}

float Random::Range(float left, float right) {
	return left + Next() * (right - left + 1);
}

float Random::Next() {
	return (float)rand() / (float)RAND_MAX;
}