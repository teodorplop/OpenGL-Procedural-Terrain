#include "TimeFrame.h"
#include "Engine.h"
#include <GL/freeglut.h>

#define DELTA_TIME 16.666666f

bool TimeFrame::running = false;
float TimeFrame::lastUpdate = 0.0f;

void TimeFrame::Start() {
	if (!running) {
		running = true;
		glutIdleFunc(IdleFunction);
	}
}
void TimeFrame::Stop() {
	if (running) {
		running = false;
		glutIdleFunc(NULL);
	}
}
float TimeFrame::DeltaTime() {
	return DELTA_TIME;
}

void TimeFrame::IdleFunction() {
	float now = (float)glutGet(GLUT_ELAPSED_TIME);

	if (now - lastUpdate >= DELTA_TIME) {
		while (now - lastUpdate >= DELTA_TIME) {
			lastUpdate += DELTA_TIME;
			Engine::Update();
		}
	}
}