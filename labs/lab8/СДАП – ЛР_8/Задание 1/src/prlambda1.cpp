// prlambda1.cpp
// C++ программа для демонстрации лямбда-выражения
// Автор ОЗНАКОМЛЕН и протестировал: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <bits/stdc++.h> // STL

// Функция для печати вектора
void printVector(std::vector<int> v){
	// lambda expression to print vector
	for_each(v.begin(), v.end(), [](int i) {
			std::cout << i << " ";
	});
	std::cout << std::endl;
}

// основная программа
int main(){
	// исходный вектор данных
	std::vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};
	std::cout << "Input array: ";
	printVector(v);

	// фрагмент ниже  находит первое число больше
	// find_if ищет элемент, для которого
	// функция (третий аргумент) возвращает true
	std::vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i) {
		return i > 6;
	});
	std::cout << "First number greater than 6 is: " << *p << std::endl;

	// функция для сортировки вектора, лямбда-выражение для сортировки в
	// невозрастающем порядке Компилятор может определить возвращаемый тип как bool, но здесь показано только для пояснения
	std::sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool {
		return a > b;
	});
	std::cout << "Sorted array: ";
	printVector(v);

	// функция для подсчета чисел больше или равных 5
	int count_5 = count_if(v.begin(), v.end(), [](int a) {
		return (a >= 3);
	});
	std::cout << "The number of elements greater than or equal to 3 is: " << count_5 << std::endl;

	// функция для удаления дублирующего элемента (после сортировки всех дубликатов объединяется)
	p = unique(v.begin(), v.end(), [](int a, int b) {
		return a == b;
	});

	// изменение размера вектора, чтобы сделать его равным общему различному числу
	v.resize(std::distance(v.begin(), p));
	std::cout << "Uniqued array: ";
	printVector(v);

	// функция накопления накапливает контейнер на основе
	// функции, указанной в качестве третьего аргумента
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	long long f = std::accumulate(arr, arr + 15, 1LL, [](long long i, int j) {
		return i * j;
	});
	std::cout << "Factorial of 15 is: " << f << std::endl;

	// Мы также можем получить доступ к функции, сохранив ее в переменной
	auto square = [](int i) {
		return i * i;
	};

	std::cout << "Square of 25 is: " << square(25) << std::endl;

	return 0;
}
