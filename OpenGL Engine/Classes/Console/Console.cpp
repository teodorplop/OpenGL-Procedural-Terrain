#include "Console.h"

#include "../Utils/MyMutex.h"
#include "../Terrain/TerrainSettings.h"

std::mutex myMutex;

Console* Console::instance = NULL;

void Console::Start() {
	instance = new Console();
}

Console::Console() {
	consoleThread = new std::thread(&Console::Execute, this);
}

Console::~Console() {
	consoleThread->detach();
	delete consoleThread;
}

void Console::Execute() {
	char input[50];
	while (scanf("%s", input)) {
		ExecuteCommand(input);
	}
}

void Console::ExecuteCommand(char* input) {
	std::vector<std::string> split = StringUtils::Split(input, "_");
	if (split.size() == 3) {
		if (split[0] == "set" && split[1] == "seed") {
			try {
				int value = std::stoi(split[2]);
				AddProperty("set_seed", to_string(value));
			}
			catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		} else if (split[0] == "set" && split[1] == "heightmapres") {
			try {
				int value = std::stoi(split[2]);
				AddProperty("set_heightmapres", to_string(value));
			} catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		} else if (split[0] == "set" && split[1] == "octaves") {
			try {
				int value = std::stoi(split[2]);
				AddProperty("set_octaves", to_string(value));
			} catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		}
	}
}

void Console::AddProperty(const std::string& prop, const std::string& value) {
	myMutex.lock();
	FileUtils::ClearFileContent("terrainSettings.txt");
	myMutex.unlock();

	std::string fileContent = prop + "_" + value;

	myMutex.lock();
	FileUtils::WriteContent("terrainSettings.txt", fileContent);
	myMutex.unlock();
}