#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Image.h"
#include "../lib/stb_image.h"
#include "../lib/stb_image_write.h"
#include <iostream>

Image::Image(const char *filename){ // ! Constructor
    if (read(filename)){
        std::cout << "Read: " << filename << std::endl;
        size = w * h * channels;
    }
    else {
        std::cout << "Failed to read: " << filename << std::endl;
    };
};

Image::~Image(){ // ! Destructor
    stbi_image_free(data);
};

bool Image::read(const char *filename){ // ! Reads image
    data = stbi_load(filename, &w, &h, &channels, 0);
    return data != NULL;
};

int Image::readPixel(int pixel){ // ! Reads pixel and returns 0 if black or the sum of rgb values if not black
    return (data[pixel] + data[pixel + 1] + data[pixel + 2]);
};
