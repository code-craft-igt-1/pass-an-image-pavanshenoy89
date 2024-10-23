#include "image.h"
#include <cstring>
#include <memory>

Image::Image(uint32_t rows, uint32_t columns)
{
    m_pixels = std::make_unique<uint32_t[]>(rows * columns);
    m_rows = rows;
    m_columns = columns;
}

Image::Image(const Image& image)
{
    m_rows = image.m_rows;
    m_columns = image.m_columns;
    uint32_t size = m_rows * m_columns;
    m_pixels = std::make_unique<uint32_t[]>(size);
    std::memcpy(m_pixels.get(), image.m_pixels.get(), size * sizeof(uint32_t));
}

Image::~Image()
{
    
}

uint32_t Image::GetRows() const
{
    return m_rows;
}

uint32_t Image::GetColumns() const
{
    return m_columns;
}

uint32_t Image::GetPixelValue(uint32_t x, uint32_t y) const
{
    return m_pixels[x * m_columns + y];
}

void Image::SetPixelValue(uint32_t x, uint32_t y, uint32_t value)
{
	m_pixels[x * m_columns + y] = value;
}
