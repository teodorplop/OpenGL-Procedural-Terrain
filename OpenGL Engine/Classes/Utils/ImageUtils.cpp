#include "ImageUtils.h"

BYTE* ImageUtils::Load_Image(const char* filename, int* width, int* height) {
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP *dib = NULL;

	fif = FreeImage_GetFileType(filename, 0);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	if (fif == FIF_UNKNOWN)
		return NULL;

	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	if (!dib)
		return NULL;

	BYTE* result = FreeImage_GetBits(dib);
	*width = FreeImage_GetWidth(dib);
	*height = FreeImage_GetHeight(dib);

	if ((result == 0) || (width == 0) || (height == 0))
		return NULL;

	return result;
}