#pragma once
class Window {
private:
	static int width, height;
	static char* name;
	int id;

public:
	Window();
	~Window();
	int WindowID();
};

