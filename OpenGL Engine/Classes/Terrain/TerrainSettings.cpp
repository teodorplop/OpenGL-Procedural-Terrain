#include "TerrainSettings.h"
#include "..\Utils\FileUtils.h"
#include "..\Utils\StringUtils.h"
#include "..\Utils\MyMutex.h"

char* TerrainSettings::filePath = "terrainSettings.txt";

TerrainSettings::TerrainSettings(Scene* scene) {
	myMutex.lock();
	FileUtils::ClearFileContent(filePath);
	myMutex.unlock();

	this->scene = scene;
	updateCount = 0;
	seed = 0;
}

void TerrainSettings::Update() {
	updateCount = (updateCount + 1) % 60;
	if (updateCount == 0) {
		myMutex.lock();
		std::string fileContent = FileUtils::GetFileContents(filePath);
		myMutex.unlock();

		ProcessContent(fileContent);
	}
}

void TerrainSettings::ProcessContent(const std::string& content) {
	if (content.size() >= 8 && content.substr(0, 8) == "set_seed") {
		try {
			int value = std::stoi(content.substr(9));
			scene->SetSeed(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 16 && content.substr(0, 16) == "set_heightMapRes") {
		try {
			int value = std::stoi(content.substr(17));
			scene->SetHeightMapRes(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 11 && content.substr(0, 11) == "set_octaves") {
		try {
			int value = std::stoi(content.substr(12));
			scene->SetOctaves(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 15 && content.substr(0, 15) == "set_terrainSize") {
		try {
			float value = std::stof(content.substr(16));
			scene->SetTerrainSize(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 17 && content.substr(0, 17) == "set_terrainHeight") {
		try {
			float value = std::stof(content.substr(18));
			scene->SetTerrainHeight(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	}
}