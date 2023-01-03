#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Image.h"
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>

Image::Image(const char *filename){
    if (read(filename)){
        std::cout << "Read: " << filename << std::endl;
        size = w * h * channels;
    }
    else {
        std::cout << "Failed to read: " << filename << std::endl;
    };
};

Image::Image(int w, int h, int channels){
    size = w * h * channels;
    data = new uint8_t[size];
};

Image::~Image(){
    stbi_image_free(data);
};

bool Image::read(const char *filename){
    data = stbi_load(filename, &w, &h, &channels, 0);
    return data != NULL;
};

int Image::readPixel(int pixel){
    //std::cout << data[pixel] + data[pixel + 1] + data[pixel + 2] << std::endl;
    return (data[pixel] + data[pixel + 1] + data[pixel + 2]) / 3;
};
