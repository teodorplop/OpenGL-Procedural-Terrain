#ifndef __TIME_FRAME_H__
#define __TIME_FRAME_H__

class TimeFrame {
private:
	static bool running;
	static float lastUpdate;
	static void IdleFunction();

public:
	static void Start();
	static void Stop();
};

#endif//__TIME_FRAME_H__