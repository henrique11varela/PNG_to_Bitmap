#include "class/Image.h"
#include <iostream>
#include <iomanip>
#include <fstream>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "Please insert the image path after the executable" << std::endl << std::endl
                  << "Example for a single line output" << std::endl
                  << "   PNG_to_Bitmap.exe image.png" << std::endl << std::endl
                  << "Example for a multiple line output" << std::endl
                  << "   PNG_to_Bitmap.exe image.png a" << std::endl << std::endl;
        return 1;
    }

    Image img(argv[1]);

    int *imgBits = new int[img.w * img.h];

    for (int i = 0; i < (img.w * img.h); i++)
    {
        imgBits[i] = (img.data[i * img.channels] == 0) ? 1 : 0;
    }

    std::string fileName = argv[1];
    int length = fileName.length();
    fileName[length - 3] = 't';
    fileName[length - 2] = 'x';
    fileName[length - 1] = 't';
    std::cout << "The output is in: " << fileName << std::endl;

    std::ofstream outputFile;

    outputFile.open(fileName);

    for (int i = 0; i < (img.w * img.h); i++)
    {
        if (i == 0)
            outputFile << "0b" << imgBits[i];
        else if (i % 8 == 0 && i != 0)
        {
            outputFile << ",";
            if (argc > 2)
                outputFile << std::endl;
            else
                outputFile << " ";
            outputFile << "0b" << imgBits[i];
        }
        else
            outputFile << imgBits[i];
    }

    outputFile.close();

    /*for (int i = 0; i < (img.h); i++)
    {
        for (int j = 0; j < (img.w); j++)
        {
            std::cout << imgBits[i * img.w + j];
        }
        std::cout << std::endl;
    }*/

    return 0;
}
