#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <iostream>
int main() {
        RgbImg img = readRgbImg("totaly_normal_rainbow.bmp");
        RgbImg recoloured = createRgbImg(img.height, img.width);
        for (size_t row = 0; row < img.width; ++row)
            for (size_t col = 0; col < img.height; ++col)
            {
                int tmp;
                tmp = img.pixels[col][row].Red;
                recoloured.pixels[col][row].Red = img.pixels[col][row].Blue;
                recoloured.pixels[col][row].Blue = tmp;
            }
        writeRgbImg("recoloured_rainbow.bmp", recoloured);
        deleteRgbImg(img);
        deleteRgbImg(recoloured);
        return 0;
    }
