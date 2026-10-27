// testSet1.cpp
// C++ программа-пример использования контейнера set
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <iostream>
#include <vector>
#include <set>
#include <iterator>

int main() {
	int len_v;
	std::set<int> s; // зададим  s как контейнер set
	int v[] = {7, 6, 1, 4, 2, 9, 10, 5, 3, 7, 5}; // массив данных

	std::cout << "Input data: ";
	len_v = (sizeof(v) / sizeof(*v)); // вычисляем длину массива
	for (int i = 0; i < len_v; i++)  // вывод элементов массива данных
		std::cout << v[i] << " ";
	std::cout << std::endl;

	s.insert(v, v + len_v); // вставляем данные в контейнер set

	std::cout << "Set elements: ";
	// вывод элементов множества в стандартный поток вывода
	std::copy(s.begin(),s.end(), std::ostream_iterator<int>(std::cout," "));
	std::cout << "\n";

	return 0;
}
