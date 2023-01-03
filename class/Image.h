#include <stdint.h>

struct Image {
    uint8_t *data = NULL;
    size_t size = 0;
    int w;
    int h;
    int channels;

    Image(const char* filename);
    Image(int w, int h, int channels);
    ~Image();

    bool read(const char* filename);
    int readPixel(int pixel);
};