#include "TimeFrame.h"
#include "Engine.h"
#include <GL/freeglut.h>

#define DELAY 16.666666f

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

void TimeFrame::IdleFunction() {
	float now = (float)glutGet(GLUT_ELAPSED_TIME);

	if (now - lastUpdate >= DELAY) {
		while (now - lastUpdate >= DELAY) {
			lastUpdate += DELAY;
			Engine::Update();
		}
	}
}