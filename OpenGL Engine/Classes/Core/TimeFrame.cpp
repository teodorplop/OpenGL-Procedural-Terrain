#include "TimeFrame.h"
#include <cstdio>

float TimeFrame::lastUpdate = 0.0f;
float TimeFrame::lastFPSPrint = 0.0f;
int TimeFrame::frames = 0;

float TimeFrame::deltaTime = 0.0f;
float TimeFrame::fps = 0.0f;

void TimeFrame::Update(float time) {
	++frames;

	deltaTime = time - lastUpdate;
	lastUpdate = time;

	if (time - lastFPSPrint >= 1.0f) {
		fps = (float)frames / (time - lastFPSPrint);
		lastFPSPrint = time;
		frames = 0;

		//printf("FPS: %f\n", fps);
	}
}