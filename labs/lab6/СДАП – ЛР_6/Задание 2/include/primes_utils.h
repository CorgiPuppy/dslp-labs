// primes_utils.h
// Модуль для работы с простыми числами
// Автор: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#ifndef PRIMES_UTILS_H
#define PRIMES_UTILS_H

#include <vector>

// Проверка числа на простоту
bool isPrime(int num);

// генерация массива простых чисел, меньших n
// возвращает количество найденных простых чисел
int gen_primes(int* primes, int n);

// функция для нахождения всех простых делителей числа N с учётом кратности
std::vector<int> getPrimeFactors(int N);

// функция, чтобы посчитать сколько раз простое P входит в факторизацию числа x
long long countPower(long long x, long long P);

// функция, чтобы посчитать сколько раз простое P встречается во всех числах от L до R
long long countInRange(long long L, long long R, long long P);

#endif
