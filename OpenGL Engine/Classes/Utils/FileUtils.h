#pragma once

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class FileUtils {
public:
	static string GetFileContents(const char* filePath);
};