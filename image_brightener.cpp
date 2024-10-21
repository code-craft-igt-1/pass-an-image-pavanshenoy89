#include "image_brightener.h"

// For brightening, we add a certain grayscale (25) to every pixel.
const int BRIGHTENING_VALUE = 25;
const int MAX_PIXEL_VALUE = 255;

ImageBrightener::ImageBrightener(Image& inputImage) : m_inputImage(inputImage) {
}

void ImageBrightener::BrightenWholeImage() {
	unsigned int attenuatedPixelCount = 0;
	for (unsigned int x = 0; x < m_inputImage.GetRows(); x++) {
		for (unsigned int y = 0; y < m_inputImage.GetColumns(); y++) {
			BrightenPixel(x, y);
		}
	}
}

void ImageBrightener::BrightenPixel(unsigned int x, unsigned int y) {
	int pixelIndex = x * m_inputImage.GetColumns() + y;
	if (m_inputImage.GetPixelValue(pixelIndex) > (MAX_PIXEL_VALUE - BRIGHTENING_VALUE)) {
		m_inputImage.SetPixelValue(pixelIndex ,MAX_PIXEL_VALUE);
		++m_attenuatedPixelCount;
	}
	else {
		m_inputImage.SetPixelValue(pixelIndex, m_inputImage.GetPixelValue(pixelIndex) + BRIGHTENING_VALUE);
	}
}

Image ImageBrightener::GetImage() {
	return m_inputImage;
}

unsigned int ImageBrightener::GetAttenuatedPixelCount()
{
	return m_attenuatedPixelCount;
}
