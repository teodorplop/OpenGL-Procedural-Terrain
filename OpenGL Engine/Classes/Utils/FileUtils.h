#ifndef __FILE_UTILS_H__
#define __FILE_UTILS_H__

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class FileUtils {
public:
	static string GetFileContents(const char* filePath);
};

#endif //__FILE_UTILS_H__