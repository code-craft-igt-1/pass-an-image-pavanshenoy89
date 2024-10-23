#pragma once
#include"image.h"

class ImageBrightener {
public:
    ImageBrightener(Image& inputImage);
    void BrightenWholeImage(uint32_t brightenValue);
    uint32_t GetAttenuatedPixelCount() const;

private:
    void BrightenPixel(uint32_t x, uint32_t y, uint32_t brightenValue);

private:
    Image m_inputImage;
    uint32_t m_attenuatedPixelCount;
};
