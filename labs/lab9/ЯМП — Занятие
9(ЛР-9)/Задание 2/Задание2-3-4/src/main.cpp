/* main.cpp
 * Автор: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович
 * СДАП Лабораторная работа 9
 * Язык: C++
 */
#include <iostream>
#include <locale>

class summator {
	// данные (св-во)
	private:
		double acc = 0;

	// методы
	public:
		void set_acc(double n) { acc = n; } // установит значение сумматора
		double get_acc() { return acc; } // извлечь значение сумматора
		void add(double n) { acc += n; } // прибавить число к сумматору
		void show() { std::cout << "acc value = " << acc << std::endl; } // вывести состояние сумматора
		summator() { acc = 0; } // конструктор по умолчанию
};

class multiplier {
	// данные (св-во)
	private:
		double acc = 1.0;
		
	// методы
	public:
		void set_acc(double n) { acc = n; } // установит значение умножителя
		double get_acc() { return acc; } // извлечь значение умножителя
		void mul(double n) { acc *= n; } // умножить текущее значение на число
		void show() { std::cout << "mult acc value = " << acc << std::endl; } // вывести состояние умножителя
		multiplier() { acc = 1.0; } // конструктор по умолчанию
};

int main() {
	setlocale(LC_ALL, "Russian");

	// --- Задание 2-3 тестовый пример для класса multiplier ---
	std::cout << "=== Тест класса multiplier ===" << std::endl;
	multiplier m; // создать объект класса multiplier

	std::cout << "Состояние св-ва объекта умножитель:" << std::endl;
	m.show(); // значение при создании объекта (1)

	m.set_acc(5);
	m.show(); // значение при установке св-ва (5)

	m.mul(10);
	m.show(); // значение при умножении на 3 (15)

	m.mul(2 * m.get_acc());
	m.show(); // значение при умножении на 2 (30)
	std::cout << std::endl;
	// --- конец задания 2-3---

	// --- Задание 2-4 вычисление суммы S = sum_{k=1}^{n} k*(k+1) / 2^k ---
	std::cout << "=== Вычисление суммы S = sum_{k=1..n} k*(k+1) / 2^k ===" << std::endl;
	int n;
	std::cout << "Введите n: ";
	std::cin >> n;

	summator S; // накопительный сумматор для итоговой суммы S
	S.set_acc(0);

	for (int k = 1; k <= n; k++) {
		// Вычисляю числитель k * (k + 1) с помощью multiplier
		multiplier num;
		num.set_acc(1);
		num.mul(k);
		num.mul(k + 1);

		// Вычисляю знаменатель 2^k с помощью multiplier
		multiplier den;
		den.set_acc(1);
		for (int i = 0; i < k; i++) 
			den.mul(2);

		// Прибавляю очередное слагаемое k*(k+1) / 2^k к сумматору S
		S.add(num.get_acc() / den.get_acc());
	}	

	std::cout << "Результат вычисления суммы S: ";
	S.show();
	// --- конец задания 2-4---

	return 0;
}
