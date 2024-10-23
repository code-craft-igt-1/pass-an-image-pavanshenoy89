#include <cstdint>
#include <memory>

class Image {
public:
    Image(uint32_t rows, uint32_t columns);
    Image(const Image& image);
    Image& operator=(const Image& image) =delete;
    ~Image();

    uint32_t GetRows() const;
    uint32_t GetColumns() const;  
    uint32_t GetPixelValue(uint32_t x, uint32_t y) const;
	void SetPixelValue(uint32_t x, uint32_t y, uint32_t value);

private:
    uint32_t m_rows;
    uint32_t m_columns;
    std::unique_ptr<uint32_t[]> m_pixels;
};