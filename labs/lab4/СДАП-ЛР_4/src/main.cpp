/* Автор: студент группы ЗОМ34-ПВШ2616
 * СДАП Лабораторная работа 4
 * Язык: C++
 */

#include <iostream>
#include <vector>
#include <iomanip>

// Функция для вычисления операции
double calculateOperations(double, char, double);

int main() {
	// Вводим размер последовательностей
	int n;
	std::cout << "Введите n (от 3 до 10 (включительно)): ";
	std::cin >> n;

	if (n < 3 || n > 10)
		// В данном контексте из задания требуется определённый размер последовательностей из некоторого интервала
		throw std::invalid_argument("Ошибка: число не из нужного диапазона.");
	
	// Инициализирую и задаю размер n для динамических массивов: двух последовательной и операций
	std::vector<double> x(n), y(n);
	std::vector<char> o(n);

	std::cout << "Введите " << n << " элементов последовательности x: ";
	for (int i = 0; i < n; i++)
		std::cin >> x[i];

	std::cout << "Введите " << n << " элементов последовательности y: ";
	for (int i = 0; i < n; i++)
		std::cin >> y[i];
	
	std::cout << "Введите " << n << " символов операций (без пробелов, например +*-/^): ";
	for (int i = 0; i < n; i++)
		std::cin >> o[i];
	
	std::cout << std::fixed << std::setprecision(3);
	std::cout << std::endl << "Вычисления на каждом из этапов:" << std::endl;

	// Инициализирую переменную под именем sum и задаю ей значение 0
	double sum = 0.0;
	try {
		for (int i = 0; i < n; i++) {
			double result = calculateOperations(x[i], o[i], y[i]);
			std::cout << x[i] << " " << o[i] << " " << y[i] << " = " << result << std::endl;

			// Прибавляем каждой результат выполнения операции к общей сумме
			sum += result;
		}
	} catch (const std::exception &e) {
		std::cout << "Ошибка: " << e.what() << std::endl;
		return 1;
	}

	// Вывод суммы после всех вычислений
	std::cout << std::endl << "Сумма = " << sum << std::endl;

	return 0;
}

double calculateOperations(double x, char operation, double y) {
	switch (operation) {
		case '+':
			return x + y;
		case '*':
			return x * y;
		case '-':
			return x - y;
		case '/': {
			if (y == 0.0)
				throw std::runtime_error("Ошибка: деление на ноль!");
			return x / y;
		}
		case '^': {
			int result = 1;
			for (int i = 0; i < y; i++)
				result *= x;
			return result;
		}
		default:
			throw std::runtime_error(std::string("Неизвестная операция: ") + operation);
	}
}
