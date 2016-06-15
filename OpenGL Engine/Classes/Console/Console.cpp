#include "Console.h"

#include "../Utils/MyMutex.h"
#include "../Terrain/TerrainSettings.h"

std::mutex myMutex;

Console* Console::instance = NULL;

void Console::Start() {
	if (instance == NULL) {
		instance = new Console();
	}
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
	if (split.size() == 1) {
		if (split[0] == "help") {
			PrintHelp();
		} else {
			printf("Unknown command.\n");
		}
	} else if (split.size() == 3) {
		if (split[0] == "set" && split[1] == "seed") {
			try {
				int value = std::stoi(split[2]);
				AddProperty("set_seed", to_string(value));
			}
			catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		} else if (split[0] == "set" && split[1] == "heightMapRes") {
			try {
				int value = std::stoi(split[2]);
				AddProperty("set_heightMapRes", to_string(value));
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
		} else if (split[0] == "set" && split[1] == "terrainSize") {
			try {
				float value = std::stof(split[2]);
				AddProperty("set_terrainSize", to_string(value));
			} catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		} else if (split[0] == "set" && split[1] == "amplitude") {
			try {
				float value = std::stof(split[2]);
				AddProperty("set_amplitude", to_string(value));
			} catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		} else if (split[0] == "set" && split[1] == "water" && (split[2] == "on" || split[2] == "off")) {
			AddProperty("set_water", split[2]);
		} else if (split[0] == "set" && split[1] == "smooth") {
			try {
				float value = std::stof(split[2]);
				AddProperty("set_smooth", to_string(value));
			} catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		} else if (split[0] == "set" && split[1] == "persistence") {
			try {
				int value = std::stoi(split[2]);
				AddProperty("set_persistence", to_string(value));
			} catch (std::invalid_argument) {
				printf("Invalid argument.\n");
			}
		} else {
			printf("Unknown command.\n");
		}
	} else {
		printf("Unknown command.\n");
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

void Console::PrintHelp() {
	printf("\n-----------------------------\nList of available commands:\n-----------------------------\n");
	printf("help -> Prints a list of avaiable commands.\n");
	printf("set_seed_x -> Sets the seed used to generate Perlin Noise to x.\n");
	printf("set_heightMapRes_x -> Sets the height map texture resolution to x * x.\n");
	printf("set_octaves_x -> Sets the number of octaves from Perlin Noise to x.\n");
	printf("set_amplitude_x -> Sets the amplitudine from Perlin Noise to x.\n");
	printf("set_persistence_x -> Sets the persistence from Perlin Noise to x.\n");
	printf("set_smooth_x -> Sets the smoothness from Perlin Noise to x.\n");
	printf("set_terrainSize_x -> Sets the length and width of the terrain to x.\n");
	printf("set_water_on -> Enables water.\n");
	printf("set_water_off -> Disables water.\n");
	printf("-----------------------------\n");
}