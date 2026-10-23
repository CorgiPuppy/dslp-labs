// Автор: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей
// СДАП Лабораторная работа 2, Задача 2
// Язык: C++

#include <iostream>
#include <cmath>
#include <iomanip>

// Структура данных Point (точка на плоскости)
struct Point {
	double x, y;

	// Конструктор
	Point(
		double x_temp = 0.0,
		double y_temp = 0.0):
		x(x_temp),
		y(y_temp)
	{}

	// Евклидово расстояние до другой точки
	double distanceTo(const Point& anotherPoint) const {
			double distanceX = x - anotherPoint.x;
			double distanceY = y - anotherPoint.y;
			return std::sqrt(distanceX * distanceX + distanceY * distanceY);
	}
};

int main() {
	// Определяю структуры точки для каждой координаты
	Point A = {1.0, 2.0};
	Point B = {3.0, 6.0};
	Point C = {7.0, 1.0};
	/* Объявил структуру Point для 3 точек треугольника и инициализировал двумя координатами для каждой.
	 * Объявил длины сторон треугольника в отдельные переменные и инициализировал их значениями, полученными из метода, которые находит расстояние от одной точки до другой.
	 * Объявил переменную для хранения значения площади и инициализировал её значением, полученным через формулу векторного произведения пополам.
	 * Затем все полученные значения и истинные значения из условия задачи.
	 */

	// Длины сторон
	double ab = A.distanceTo(B);  // f
	double bc = B.distanceTo(C);  // g
	double ca = C.distanceTo(A);  // h

	// Площадь через векторное произведение (половина модуля)
	double area = std::fabs((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)) / 2.0;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Треугольник ABC:" << std::endl;
	std::cout << "  A = (" << A.x << ", " << A.y << ")" << std::endl;
	std::cout << "  B = (" << B.x << ", " << B.y << ")" << std::endl;
	std::cout << "  C = (" << C.x << ", " << C.y << ")" << std::endl;
	std::cout << std::endl;
	std::cout << "Сторона AB (f) = " << ab << std::endl;
	std::cout << "Сторона BC (g) = " << bc << std::endl;
	std::cout << "Сторона CA (h) = " << ca << std::endl;
	std::cout << std::setprecision(0);
	std::cout << "Площадь ABC    = " << area << std::endl;
	// Контроль: f=4.47, g=6.40, h=6.08, площадь=13

	return 0;
}
