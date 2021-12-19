#include <iostream>
int main() {
	setlocale(LC_ALL, "ru");
	double Rad, counter = 0;
	std::cout << "Введите радиус окружности: "; std::cin >> Rad;
	for (double y = 1.; y <= Rad; y += 1.){
		for (double x = 1.; x <= Rad; x += 1.){
			if ((x * x + y * y) <= Rad * Rad)
				++counter;
		}
	}
	counter *= 4;
	counter += 4 * Rad + 1;
	std::cout << "Количество точек с целочисленными координатами равно: " << counter;
  return 0;
}
