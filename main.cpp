#include "Image.h"
#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "not enough arguments, please insert an image\n";
    }

    Image img(argv[1]);
    /*for (int i = 0; i < img.h * img.w * img.channels; i += img.channels)
    {
        std::cout << img.readPixel(i) << std::endl;
    }*/

    for (int i = 0; i < img.h; i++)
    {
        for (int j = 0; j < img.w; j++)
        {
            int pixelInfo = 0;
            for (int k = 0; k < img.channels; k++)
            {
                pixelInfo += img.data[(i * img.w * img.channels) + (j * img.channels) + k];
            }
            std::cout << std::setw(3) << pixelInfo / 3 << " ";
        }
        std::cout << std::endl;
    }
    

    return 0;
}
