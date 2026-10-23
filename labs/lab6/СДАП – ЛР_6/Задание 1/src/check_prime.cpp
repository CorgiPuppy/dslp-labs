// check_prime.cpp
// C++ программа для проверки простоты числа (рекурсивная)
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <iostream>
#include <cmath>

// рекурсивная функция для проверки числа на простоту
int checkPrime(int, int);

int main() {
	int num;
	std::cout << "Enter your number: ";
	std::cin >> num;

	if (checkPrime(2, num) == 0)
		std::cout << "Number " << num << " is a primer." << std::endl;
	else
		std::cout << "Number " << num << " isn't a primer." << std::endl;
		
	return 0;
}

// принимаю 2 (минимальное простое число) и само рассматриваемое число
int checkPrime(int i, int num) {
	// если мы дошли до самого числа, то, очевидно, у него не было делителей, кроме него самого и 1, поэтому выводим 0 (то есть правду)
	if (num == i) return 0; 
	// если число делится на число от 2 до num -1, то оно имеет хотя бы один третий делитель (помимо 1 и самого числа), значит выводим, что число не простое
	else if (num % i == 0) return 1; 
	// иначе идём рассматривать следующий делитель
	else return checkPrime(i + 1, num);
}
