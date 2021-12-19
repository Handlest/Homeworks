#include <iostream>
#include "Matrix.h"
#include <ctime>
int main() {

	double** matrixA = createMatrix(3, 3);
	inputMatrix(matrixA, 3, 3);
	std::cout << "\n";
	for (size_t rows = 0; rows < 3; ++rows) {
		for (size_t cols = 0; cols < 3; ++cols) {
			std::cout << matrixA[rows][cols] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "Determinant of your matrix: " << determinant(matrixA, 3) << "\n";
	double** inverse = inv(matrixA, 3);
	std::cout << "Inverse Matrix:" << "\n";
	for (size_t rows = 0; rows < 3; ++rows) {
		for (size_t cols = 0; cols < 3; ++cols) {
			std::cout << inverse[rows][cols] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (size_t r = 0; r < 3; ++r) {
		double* lMin = &localMinimum(matrixA, r, 3);
		*lMin = 0;
	}
	for (size_t rows = 0; rows < 3; ++rows) {
		for (size_t cols = 0; cols < 3; ++cols) {
			std::cout << matrixA[rows][cols] << "\t";
		}
		std::cout << "\n";
	}
	deleteMatrix(matrixA, 3, 3);
	deleteMatrix(inverse, 3, 3);
	return 0;
}
