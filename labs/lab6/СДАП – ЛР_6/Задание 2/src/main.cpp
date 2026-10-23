/* Автор: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович
 * СДАП Лабораторная работа 6
 * Язык: C++
 */

#include "../include/primes_utils.h"

#include <iostream>
#include <vector>

int main() {
	/*
	 * Задача 1
	 * нахождение простых делителей числа (с повторениями) или NOT
	 */
	std::cout << "--- Задача 1 ---" << std::endl;
	std::cout << "Введите число N: ";
	int N;
	std::cin >> N;

	if (isPrime(N)) {
		std::cout << "Результат: NOT (число простое)" << std::endl;
	} else {
		std::vector<int> factors = getPrimeFactors(N);
		std::cout << "Простые делители: ";
		for (int i = 0; i < factors.size(); i++) {
			std::cout << factors[i];
			if (i + 1 < factors.size()) std::cout << " ";
		}
		std::cout << std::endl;
	}	
	std::cout << std::endl;
	/*
	 * Конец задачи 1
	 */

	/*
	 * Задача 2
	 * сколько раз простое P встречается в разложении чисел [L, R]
	 */
	std::cout << "--- Задача 2 ---" << std::endl;
	std::cout << "Введите L, R и P (P - простое): ";
	long long L, R, P;
	std::cin >> L >> R >> P;

	long long result = countInRange(L, R, P);
	std::cout << "Количество вхождений P в разложениях чисел от " << L << " до " << R << ": " << result << std::endl;
	/*
	 * Конец задачи 2
	 */
	return 0;
}
