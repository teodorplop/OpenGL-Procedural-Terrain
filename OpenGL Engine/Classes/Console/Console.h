#pragma once

#include<thread>

#include "../Utils/FileUtils.h"
#include "../Utils/StringUtils.h"

class Console {
private:
	static Console* instance;

	std::thread* consoleThread;
	Console();
	~Console();

	void Execute();
	void ExecuteCommand(char* input);
	void PrintHelp();
	static void AddProperty(const std::string& prop, const std::string& value);

public:
	static void Start();
};