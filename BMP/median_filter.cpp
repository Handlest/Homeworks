#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <iostream>
void insertionSort(int[], int);
int main() {
    int n = 5;
    RgbImg img = readRgbImg("kidsnoise.bmp");
    RgbImg output = createRgbImg(img.height, img.width);
    int half = n / 2;
    int* mas_r = new int[n * n];
    int* mas_g = new int[n * n];
    int* mas_b = new int[n * n];
    for (size_t row = half; row < img.height - half; ++row)
    {
        for (size_t col = half; col < img.width - half; ++col)
        {
            for (size_t i = 0; i < n; ++i)
                for (size_t j = 0; j < n; ++j)
                {
                    size_t i_m = row + i - half, j_m = col - half + j;
                    mas_r[i * 3 + j] = img.pixels[i_m][j_m].Red;
                    mas_g[i * 3 + j] = img.pixels[i_m][j_m].Green;
                    mas_b[i * 3 + j] = img.pixels[i_m][j_m].Blue;
                }
            insertionSort(mas_r, n * n);
            insertionSort(mas_g, n * n);
            insertionSort(mas_b, n * n);

            output.pixels[row][col].Red = mas_r[n * n / 2];
            output.pixels[row][col].Green = mas_g[n * n / 2 ];
            output.pixels[row][col].Blue = mas_b[n * n / 2];


        }
    }
    delete[] mas_b;
    delete[] mas_r;
    delete[] mas_g;
    writeRgbImg("kids_median_filtered.bmp", output);
    deleteRgbImg(output);
    deleteRgbImg(img);
    return 0;
}


void insertionSort(int data[], int lenD)
{
    int key = 0;
    int i = 0;
    for (int j = 1; j < lenD; j++) {
        key = data[j];
        i = j - 1;
        while (i >= 0 && data[i] > key) {
            data[i + 1] = data[i];
            i = i - 1;
            data[i + 1] = key;
        }
    }
}
