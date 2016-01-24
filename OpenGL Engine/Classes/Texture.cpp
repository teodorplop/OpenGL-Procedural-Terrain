#include "Texture.h"
#include "Utils\ImageUtils.h"

Texture::Texture(const std::string& fileName, bool hasTransparency) : fileName(fileName) {
	BYTE* pixels = ImageUtils::Load_Image(fileName.c_str(), &width, &height);
	this->hasTransparency = hasTransparency;

	glGenTextures(1, &textureID);
	Bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
	Unbind();
}

Texture::~Texture() {
	glDeleteTextures(1, &textureID);
}

bool Texture::HasTransparency() {
	return hasTransparency;
}

void Texture::Bind(int index) {
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}