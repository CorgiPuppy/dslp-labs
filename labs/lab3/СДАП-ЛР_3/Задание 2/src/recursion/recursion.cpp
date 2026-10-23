// Автор: Студент группы ЗОМ34-ПВШ2616 Золотухин Андрей
// СДАП Лабораторная работа 3, Задание 2b - рекурсивный алгоритм
// Язык: C++

#include <iostream>
#include <cmath>
#include <iomanip>

// Рекурсивное вычисление кубического корня из a по формуле: x_{n+1} = (2*x_{n} + a / x_{n}^{2) / 3.
double calculateCubeRoot(double a, double x, double eps = 1e-3) {
	double nextValue = (2.0 * x + a / (x * x)) / 3.0;

	// Считаю, пока не достигну заданной мной точности (по формуле |x_{на текущей итерации} - x_{на предыдущей итерации}| <= точность)
	if (std::fabs(nextValue - x) <= eps)
		return nextValue;

	// Рекурсивно вызываю функцию
	return calculateCubeRoot(a, nextValue, eps);
}

// Для задания начального приближения
double calculateCubeRoot(double a, double eps = 1e-3) {
	// Очевидно, что если a = 0, то ответ 0
	if (a == 0.0)
		return 0.0;
	return calculateCubeRoot(a, a, eps);
}

int main() {
	double a[] = {10.0, 15.0};

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Рекурсивный алгоритм\n" << std::endl;

	for (double number: a) {
		double result = calculateCubeRoot(number);
		std::cout << "a = " << number << std::endl;
		std::cout << "cbrt(a) = " << result << std::endl;
		std::cout << "Проверка: cbrt(a)^3 = " << result * result * result << std::endl << std::endl;
	}
	return 0;
}
