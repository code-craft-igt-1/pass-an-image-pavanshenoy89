#include <cstdint>
#include <memory>

class Image {
public:
    Image(uint32_t rows, uint32_t columns);
    Image(const Image& image); // Copy constructor
    ~Image();

    uint32_t GetRows();
    uint32_t GetColumns();
    
    uint32_t GetPixelValue(uint32_t pixelIndex);
	void SetPixelValue(uint32_t pixelIndex, uint32_t value);

private:
    uint32_t m_rows;
    uint32_t m_columns;
    std::unique_ptr<uint8_t[]> m_pixels;
};