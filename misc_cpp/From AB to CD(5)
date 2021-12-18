#include <iostream>
int main(){
    setlocale(LC_ALL, "ru");
    double a, b, c, d, x;
    std::cout << "Введите через пробел координаты точек A, B для первого отрезка: ";
    std::cin >> a >> b;
    std::cout << "Введите через пробел координаты точек C, D для первого отрезка: ";
    std::cin >> c >> d;
    std::cout << "Введите координату точки х: x = ";
    std::cin >> x;

    std::cout << "Точка y на втором отрезке = " << c + (x - a) * (d - c) / (b - a) << std::endl;
    return 0;
}
