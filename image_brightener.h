#pragma once
#include"image.h"


class ImageBrightener {
public:
    ImageBrightener(Image& inputImage);
    void BrightenWholeImage();
    void BrightenPixel(uint32_t x, uint32_t y);
    Image GetImage();
    uint32_t GetAttenuatedPixelCount();


private:
    Image m_inputImage;
    uint32_t m_attenuatedPixelCount;
};
