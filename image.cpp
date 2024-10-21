#include "image.h"
#include <cstring>
#include <memory>

Image::Image(unsigned int rows, unsigned int columns)
{
    m_pixels = std::make_unique<uint8_t[]>(rows * columns);
    m_rows = rows;
    m_columns = columns;
}

Image::Image(const Image& image)
{
    m_rows = image.m_rows;
    m_columns = image.m_columns;
    int size = m_rows * m_columns;
    m_pixels = std::make_unique<uint8_t[]>(size);
    std::memcpy(m_pixels.get(), image.m_pixels.get(), size * sizeof(uint8_t));
}

Image::~Image()
{
    
}

unsigned int Image::GetRows()
{
    return m_rows;
}

unsigned int Image::GetColumns()
{
    return m_columns;
}

unsigned int Image::GetPixelValue(unsigned int pixelIndex)
{
    return m_pixels[pixelIndex];
}

void Image::SetPixelValue(unsigned int pixelIndex, unsigned int value)
{
	m_pixels[pixelIndex] = value;
}
