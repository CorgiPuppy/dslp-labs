// primes_utils.cpp
// Реализация модуля работы с простыми числами
// Автор: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

// импортирую головной файл, где были инициализированы эти модули
#include "../include/primes_utils.h"

#include <cmath>
#include <vector>

// рекурсивная функция для проверки числа на простоту
int checkPrimeRec(int i, int num) {
	// если мы дошли до самого числа, то, очевидно, у него не было делителей, кроме него самого и 1, поэтому выводим 0 (то есть правду)
	if (num == i) return 0;
	// если число делится на число от 2 до num -1, то оно имеет хотя бы один третий делитель (помимо 1 и самого числа), значит выводим, что число не простое
	if (num % i == 0) return 1;             
	// иначе идём рассматривать следующий делитель
	return checkPrimeRec(i + 1, num);
}
bool isPrime(int num) {
    if (num <= 1) return false;
    return checkPrimeRec(2, num) == 0;
}

// Генерация простых чисел
int gen_primes(int* primes, int n) {
    if (n < 2) return 0;

    int k = (int)std::sqrt(n + 1);
    int* buf = new int[n];

    // заполняем буфер числами от 2 до n
    buf[0] = 2;
    for (int i = 1; i < n; i++)
        buf[i] = i + 1;

    int p = 0;
    int pk = 0;

    while (p < k) {
        // вычёркиваю кратные текущему простому
        int m = p + 1;
        while (m < n) {
            if (buf[m] != -1 && buf[m] % buf[p] == 0)
                buf[m] = -1;
            m++;
        }

        // собираю оставшиеся числа
        pk = 0;
        for (int i = 0; i < n; i++) {
            if (buf[i] != -1)
                primes[pk++] = buf[i];
        }

        // обновляю буфер
        for (int i = 0; i < n; i++)
            buf[i] = (i < pk) ? primes[i] : -1;

        p++;
    }

    delete[] buf; // освобождаю память

    return pk;
}

// Модуль-функция для нахождения простых делителей с кратностью 
std::vector<int> getPrimeFactors(int N) {
    std::vector<int> factors;
    if (N <= 1) return factors;

    // двойка
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    // нечётные делители
    for (int i = 3; i * 1LL * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    // оставшееся простое
    if (N > 1)
        factors.push_back(N);

    return factors;
}

// модуль-функция для подсчёта степени простого в одном числе
long long countPower(long long x, long long P) {
    long long counter = 0;
    while (x > 0 && x % P == 0) {
        counter++;
        x /= P;
    }
    return counter;
}

// модуль-функция для подсчёта в диапазоне [L, R]
long long countInRange(long long L, long long R, long long P) {
    long long total = 0;
    for (long long i = L; i <= R; i++)
        total += countPower(i, P);
    return total;
}
