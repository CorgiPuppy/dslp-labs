// tab_primes1.cpp
// C++ программа для таблицы простых чисел, меньших n
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <iostream>
#include <iomanip>
#include <cmath>
int main(){
 	int m, p, pk, n;
 	std::cout << "n = ";
 	std::cin >> n;
 	std::cout << "Numbers: " << n << std::endl;
 	int k = (int)std::sqrt(n + 1);

 	int *buf = new int[n];
 	int *primes = new int[n];

	// заполнение буфера числами от 2 до n
	buf[0] = 2;
	for (int i = 1; i < n; i++){
		buf[i] = i + 1;
	}
	p = 0;
  while(p<k){
		m = p + 1;
		while(m < n) {
			if (buf[m] % buf[p] == 0) buf[m] = -1;
			m++;
		}
		pk = 0;
		for (int i = 0; i < n; i++) {
			if (buf[i] != -1) {
				primes[pk] = buf[i];
				pk++;
			}
		}

		for (int i=0;i<n;i++)
			buf[i] = (i < pk) ? primes[i] : -1;
		p++;
	}

	// Вывод всех простых чисел, меньших n
	std::cout << "Primes: " << pk << std::endl;
	for (int i = 0;i < pk; i++){
		std::cout << std::setw(4) << primes[i];
		if (i % 9 == 0 && i != 0) std::cout << std::endl; // перевод строки после 9 числа
	}
	std::cout << std::endl;

	return 0;
}

