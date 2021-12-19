#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <iostream>
int main() {
    size_t const kern_sz2 = 5;
    size_t const kern_sz1 = 3;
    double** kernel = new double* [kern_sz1];
    kernel[0] = new double[kern_sz1] {0, -1, 0};
    kernel[1] = new double[kern_sz1] {-1, 5, -1};
    kernel[2] = new double[kern_sz1] {0, -1, 0};

    RgbImg img = readRgbImg("kidsnoise.bmp");
    RgbImg filtered = convolution(img, kern_sz2);
    RgbImg sharpened = convolution(filtered, kern_sz1, kernel);
    writeRgbImg("kids_filtered_kernel.bmp", filtered);
    writeRgbImg("kids_sharp_img.bmp", sharpened);
    deleteRgbImg(img);
    deleteRgbImg(filtered);
    deleteRgbImg(sharpened);

    for (size_t row = 0; row < kern_sz1; ++row)
        delete[] kernel[row];
    delete[] kernel;
}
