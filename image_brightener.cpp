#include "image_brightener.h"

const int MAX_PIXEL_VALUE = 255;

ImageBrightener::ImageBrightener(Image& inputImage) : m_inputImage(inputImage) ,m_attenuatedPixelCount(0) {
}

void ImageBrightener::BrightenWholeImage(uint32_t brightenValue) {
	for (uint32_t x = 0; x < m_inputImage.GetRows(); x++) {
		for (uint32_t y = 0; y < m_inputImage.GetColumns(); y++) {
			BrightenPixel(x, y , brightenValue);
		}
	}
}

void ImageBrightener::BrightenPixel(uint32_t x, uint32_t y , uint32_t brightenValue) {
	if (m_inputImage.GetPixelValue(x,y) > (MAX_PIXEL_VALUE - brightenValue)) {
		m_inputImage.SetPixelValue(x,y ,MAX_PIXEL_VALUE);
		++m_attenuatedPixelCount;
	}
	else {
		m_inputImage.SetPixelValue(x,y, m_inputImage.GetPixelValue(x,y) + brightenValue);
	}
}

uint32_t ImageBrightener::GetAttenuatedPixelCount() const
{
	return m_attenuatedPixelCount;
}
