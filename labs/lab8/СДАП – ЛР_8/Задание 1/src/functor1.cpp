// functor1.cpp
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

/*
 * Функторы — это объекты, которые можно рассматривать
 * как функцию или указатель на функцию.
 * Функторы чаще всего используются вместе с STL в сценарии,
 * подобном следующему:
*/
// C++ программа использует алгоритм transform() из STL
// и добавляет  1 ко всем элементам массива arr[]

#include <iostream>
#include <iomanip>
#include <algorithm>

int increment(int x) { return (x + 1); }

int main() {
	int arr[] = {1, 2, 3, 4, 5}; // массив
	int n = sizeof(arr)/sizeof(arr[0]); // размер массива
	std::cout << "Input array: ";
	for (int i = 0; i < n; i++)
			 std::cout << arr[i] << " ";
	std::cout << "\n";

	//Применяем приращение ко всем элементам
	// arr[] и сохраняем измененные элементы
	// назад в arr []
	std::transform(arr, arr+n, arr, increment);

	std::cout << "Transform array by functor: ";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	return 0;
}
