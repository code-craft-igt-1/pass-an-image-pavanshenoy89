#include <iostream>
#include "image_brightener.h"


int main() {
    uint32_t image_row_size = 512;
    uint32_t image_column_size = 512;
    Image image(image_row_size, image_column_size);

	std::cout << "Brightening a 512 x 512 image\n";
    ImageBrightener brightener(image);   
    brightener.BrightenWholeImage();
    std::cout << "Attenuated " << brightener.GetAttenuatedPixelCount() << " pixels\n";
}
