#include "FileReader.h"

string FileReader::GetFileContents(const char* filePath) {
	ifstream fileStream(filePath, ios::in);
	string content = "";
	if (fileStream.is_open()) {
		string line = "";
		while (getline(fileStream, line)) {
			content += line + "\n";
		}
		fileStream.close();
	}
	return content;
}