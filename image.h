#include <cstdint>
#include <memory>

class Image {
public:
    Image(unsigned int rows, unsigned int columns);
    Image(const Image& image); // Copy constructor
    ~Image();

    unsigned int GetRows();
    unsigned int GetColumns();
    
    unsigned int GetPixelValue(unsigned int pixelIndex);
	void SetPixelValue(unsigned int pixelIndex, unsigned int value);

private:
    unsigned int m_rows;
    unsigned int m_columns;
    std::unique_ptr<uint8_t[]> m_pixels;
};