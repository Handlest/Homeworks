#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <iostream>
int main() {
    RgbImg img = readRgbImg("totaly_normal_rainbow.bmp");
    for (size_t row = 0; row < img.width; ++row)
        for (size_t col = 0; col < img.height; ++col){
            int tmp = img.pixels[col][row].Blue;
            img.pixels[col][row].Blue = img.pixels[col][row].Red;
            img.pixels[col][row].Red = tmp;
        }
    writeRgbImg("recoloured_rainbow.bmp", img);
    deleteRgbImg(img);
    return 0;
}
