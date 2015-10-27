#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class FileReader {
public:
	static string GetFileContents(const char* filePath);
};
