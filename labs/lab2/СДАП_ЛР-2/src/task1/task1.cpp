// Автор: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей
// СДАП Лабораторная работа 2, Задача 1
// Язык: C++

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Определить числа с плавающей точкой x, y, z
    double x = 2.7; // z = 2,7
    double y = 0.5; // y = 1/2
    double z = 1.0; // z = 1
		/* Объявил 3 переменных
		 * и инициализировал их значениями из примера задачи.
		 * Затем вычисляю a и b по формуле, данной в задаче
		 * и печатаю их на экран.
		 */
    // a = (sqrt(|x-1|) - cbrt(|y|)) / (1 + x²/2 + y⁴/4)
    double a = (std::sqrt(std::abs(x - 1.0)) - std::cbrt(std::abs(y))) / (1.0 + (x * x) / 2.0 + (y * y * y * y) / 4.0);

    // b = x * (arctan(z) + e^(-(x+3)))
    double b = x * (std::atan(z) + std::exp(-(x + 3.0)));

    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << std::fixed << std::setprecision(16);
    std::cout << "a = " << a << std::endl;
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "b = " << b << std::endl;
    // Ожидаемые значения: a = 0.1094574129127381; b = 2.129609147908283

    return 0;
}
