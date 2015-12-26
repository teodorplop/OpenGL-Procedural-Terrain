#ifndef __INPUT_H__
#define __INPUT_H__

#include <unordered_map>
#include "Utils/Math/Vector3.h"

class Input {
public:
	static void Start();
	static void Update();
	static bool GetKeyDown(unsigned char key);
	static bool GetKey(unsigned char key);
	static bool GetKeyUp(unsigned char key);
	static bool GetMouseButtonDown(int button);
	static bool GetMouseButton(int button);
	static bool GetMouseButtonUp(int button);
	static Vector3 GetMousePosition();

private:
	static Input* instance;

	Input();
	~Input();

	Vector3 mousePosition;

	std::unordered_map<unsigned char, bool> keyIsDown;
	std::unordered_map<unsigned char, bool> keyIs;
	std::unordered_map<unsigned char, bool> keyIsUp;

	std::unordered_map<int, bool> mouseButtonIsDown;
	std::unordered_map<int, bool> mouseButtonIs;
	std::unordered_map<int, bool> mouseButtonIsUp;

	void UpdateHandler();
	void MotionHandler(int x, int y);
	void PassiveMotionHandler(int x, int y);
	void MouseHandler(int button, int state, int x, int y);
	void KeyboardHandler(unsigned char key, int x, int y);
	void KeyboardUpHandler(unsigned char key, int x, int y);

	static void HandleMotion(int x, int y);
	static void HandlePassiveMotion(int x, int y);
	static void HandleMouse(int button, int state, int x, int y);
	static void HandleKeyboard(unsigned char key, int x, int y);
	static void HandleKeyboardUp(unsigned char key, int x, int y);
};

#endif // __INPUT_H__