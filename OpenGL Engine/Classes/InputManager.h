#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

class InputManager {
private:
	InputManager();
	~InputManager();

	static InputManager* instance;

public:
	static void Start();
	static void HandleMouse(int button, int state, int x, int y);
	static void HandleKeyboard(unsigned char key, int x, int y);
};

#endif // __INPUT_MANAGER_H__