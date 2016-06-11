#include "Classes\Core\Engine.h"
#include "Classes\Console\Console.h"

int main(int argc, char** argv) {
	Console::Start();
	Engine::Start(argc, argv);
}