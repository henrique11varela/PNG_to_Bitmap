#include "class/Image.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

std::string Pnp_to_Bitmap(const char *imgName) // ! turns pixel info to bitmap
{
    Image img(imgName); //instance

    int *imgBits = new int[img.w * img.h]; //bit array

    for (int i = 0; i < (img.w * img.h); i++) //fills array with 1 if the red channel is 0
    {
        imgBits[i] = (img.data[i * img.channels] == 0) ? 1 : 0;
    }

    std::string fileName = imgName; //prepare name
    fileName.pop_back();
    fileName.pop_back();
    fileName.pop_back();
    fileName.pop_back();

    std::string output = fileName;

    output += ": ";

    for (int i = 0; i < (img.w * img.h); i++) // from array to string
    {
        std::string X = std::to_string(imgBits[i]);
        if (i == 0)
        {
            output += "0b";
            output += X;
        }
        else if (i % 8 == 0 && i != 0)
        {
            output += ", 0b";
            output += X;
        }
        else
            output += X;
    }
    output += "\n";
    return output; // * return
};

int main(int argc, char const *argv[])
{
    if (argc < 2) //tutorial
    {
        std::cout << "Please insert the image path after the executable" << std::endl
                  << std::endl
                  << "For a single file:" << std::endl
                  << "   PNG_to_Bitmap.exe test_image.png" << std::endl
                  << std::endl
                  << "For multiple files:" << std::endl
                  << "   PNG_to_Bitmap.exe test_image.png test_image2.png" << std::endl
                  << std::endl;
        return 1;
    }

    std::string* images = new std::string[argc - 1]; //string array to store output

    for (int i = 1; i < argc; i++) //fill string array
    {
        images[i - 1] = Pnp_to_Bitmap(argv[i]);
    }

    std::cout << "\nThe output is in 'output.txt'\n\n";

    std::ofstream outputFile; //file intance
    outputFile.open("output.txt");

    outputFile << "Each line is from an image.\n\n";

    for (int i = 0; i < argc - 1; i++)
    {
        outputFile << images[i];
    }

    outputFile.close();

    return 0;
}
