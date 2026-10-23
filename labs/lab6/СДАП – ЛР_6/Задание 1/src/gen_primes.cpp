// gen_primes.cpp
// C++ программа с модулем - функцией генерации массива простых чисел, меньших n
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <cmath>

/*  функция возвращает количество простых чисел
 *	в массиве primes из n элементов
 */
int gen_primes(int *primes,int n){
	int m, p, pk;
	int k = (int)std::sqrt(n + 1);
 	int *buf = new int[n];
	
	// заполняем буфер всеми числами от 2 до n
 	buf[0] = 2;
	for (int i = 1; i < n; i++)
		buf[i] = i + 1;
	p = 0;
	while(p < k){
		m = p + 1;
		while(m < n) {
			if (buf[m] % buf[p] == 0) buf[m] = -1;
			m++;
		}
		pk = 0;
		for (int i = 0; i < n; i++)
			if (buf[i] != -1)
				primes[pk++] = buf[i];
		for (int i = 0; i < n; i++)
	  		buf[i] = (i < pk) ? primes[i] : -1; // сократил до тернарного оператора
		p++;
	}
	
	delete[] buf; // в примере не было, но я добавил для освобождения памяти

	return pk;
} // end function
