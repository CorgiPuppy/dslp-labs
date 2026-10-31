/* Автор: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович
 * СДАП Лабораторная работа 8
 * Язык: C++
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Функция для печати вектора
void printVector(std::vector<int> v){
	std::cout << "[";
	// лямбда-выражние для вывода вектора
	int idx = 0; // использую, чтобы считать индекс
	for_each(v.begin(), v.end(), [&](int i) {
		if (idx++ != v.size() - 1) std::cout << i << ", ";  
		else std::cout << i; // на последнем элементе не вывожу запятую с пробелом
	});
	std::cout << "]" << std::endl;
}

int main() {
	/*
	 * Задача 1
	 * возведение чисел в определённую степень (в частности, в квадрат и куб)
	 */
	std::cout << "--- Задача 1 ---" << std::endl;
	std::cout << "Возведение чисел в определённую степень (в частности, в квадрат и куб)" << std::endl;
	int n = 10; // количество элементов массива
	// заполнение элементами массив от 1 до 10
	std::vector<int> v; 
	for (int i = 0; i < n; i++)
		v.push_back(i + 1);

	std::cout << "Исходный массив: ";
	printVector(v);	

	std::vector<int> squares(n); // создаю отдельный массив для записи в него элементов исходного, возведённых в квадрат	
	std::vector<int> cubes(n); // создаю отдельный массив для записи в него элементов исходного, возведённых в куб	

	// Применяю ко всем элементам вектора v и сохраняю измененные элементы в squares
	std::transform(v.begin(), v.end(), squares.begin(), [](int i) {
		return i * i;
	});	
	std::cout << "Возведите в квадрат каждое число: ";
	printVector(squares);

	// Применяю ко всем элементам вектора v и сохраняю измененные элементы в cubes
	std::transform(v.begin(), v.end(), cubes.begin(), [](int i) {
		return i * i * i;
	});
	std::cout << "Возведите в куб каждое число: ";
	printVector(cubes);
	std::cout << std::endl;
	// очистка вектора
	v.clear();
	/*
	 * Конец задачи 1
	 */

	/*
	 * Задача 2
	 * поиск чисел, делящихся на девятнадцать или тринадцать
	 */
	std::cout << "--- Задача 2 ---" << std::endl;
	std::cout << "Поиск чисел, делящихся на 19 или 13" << std::endl;

	std::cout << "Введите число элементов массива: ";
	int N;
	std::cin >> N; // чтение количества элементов массива
	std::cout << "Вводите элементы массива через пробел: ";
	std::vector<int> nums(N, 0);
	for (int i = 0; i < N; i++)
		std::cin >> nums[i];	
	
	std::cout << "Исходный массив: ";
	printVector(nums);	

	std::cout << "Числа, делящиеся на 19 или 13: ";
	// лямбда-выражение для вывода вектора, если элемент вектора делится на 19 или 13
	for_each(nums.begin(), nums.end(), [&](int val) {
		if ((val % 19 == 0) or (val % 13 == 0)) std::cout << val << " ";
	});
	std::cout << std::endl;

	// очистка вектора
	nums.clear();
	/*
	 * Конец задачи 2
	 */
			
	return 0;
}
