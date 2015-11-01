class TimeFrame {
private:
	static bool running;
	static float lastUpdate;
	static void IdleFunction();

public:
	static void Start();
	static void Stop();
};