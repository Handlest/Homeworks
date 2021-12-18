#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <iostream>
int main(){
    const char* input = "totaly_normal_rainbow.bmp";
    const char* output = "Rotated_rainbow.bmp";
    int angle;
    std::cout << "Enter the angle of rotation(multiple of 90)"; std::cin >> angle;
    RgbImg iimg = readRgbImg(input);
    size_t hei = iimg.height, wid = iimg.width;
    if (angle % 90 != 0) {
        std::cout << "Angle is not multiple of 90!\n";
        return 0;
    }
        while (angle >= 360){
            angle -= 360;
        }
        if (angle == 90)
        {
            RgbImg outputimg = createRgbImg(wid, hei, { 0, 0, 0 });
            for (size_t x = 0; x < wid; x++)
            {
                for (size_t y = 0; y < hei; y++)
                {
                    outputimg.pixels[wid - 1 - x][y] = iimg.pixels[y][x];
                }
            }
            writeRgbImg(output, outputimg);
            deleteRgbImg(iimg);
            deleteRgbImg(outputimg);
        }
        else if (angle == 180) {
            RgbImg outputimg = createRgbImg(wid, hei, { 0, 0, 0 });
            for (size_t x = 0; x < wid; x++)
            {
                for (size_t y = 0; y < hei; y++)
                {
                    outputimg.pixels[y][x] = iimg.pixels[hei - y - 1][wid - x - 1];
                }
            }
            writeRgbImg(output, outputimg);
            deleteRgbImg(iimg);
            deleteRgbImg(outputimg);
        }
        else if (angle == 270) {
            RgbImg outputimg = createRgbImg(wid, hei, { 0, 0, 0 });
            for (size_t x = 0; x < wid; x++)
            {
                for (size_t y = 0; y < hei; y++)
                {
                    outputimg.pixels[x][hei - 1 - y] = iimg.pixels[y][x];
                }
            }
            writeRgbImg(output, outputimg);
            deleteRgbImg(iimg);
            deleteRgbImg(outputimg);
    }
    return 0;
}
