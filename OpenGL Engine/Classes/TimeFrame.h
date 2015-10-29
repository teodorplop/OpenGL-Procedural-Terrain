#include "Object.h"
#include <vector>

class TimeFrame {
private:
	static bool running;
	static int lastUpdate;
	static void IdleFunction();

public:
	static void Start();
	static void Stop();
};