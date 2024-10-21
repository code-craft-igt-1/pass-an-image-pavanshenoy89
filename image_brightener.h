#pragma once
#include"image.h"


class ImageBrightener {
public:
    ImageBrightener(Image& inputImage);
    void BrightenWholeImage();
    void BrightenPixel(unsigned int x, unsigned int y);
    Image GetImage();
    unsigned int GetAttenuatedPixelCount();


private:
    Image m_inputImage;
    unsigned int m_attenuatedPixelCount;
};
