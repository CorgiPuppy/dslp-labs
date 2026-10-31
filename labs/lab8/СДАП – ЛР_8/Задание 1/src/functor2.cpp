//functor2.cpp
// C++ программа демонстрирует работу функтора
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

/*
 * Функтор (или объект функции) — это класс C++, который действует как функция.
 * Функторы вызываются с использованием того же старого синтаксиса вызова функции.
 * Чтобы создать функтор, мы создаем объект, который перегружает оператор().
*/

#include <iostream>
#include <iomanip>
#include <functional> // функторы
#include <algorithm>

// Объект Функтор
class increment {
	private:
		int num;
	public:
		increment(int n): num(n) { }
		// Эта перегрузка оператора позволяет вызывать оператор function() для объекта increment
		int operator () (int arr_num) const {
			return num + arr_num;
		}
};

// исполняемый код
	int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout << "Input array: ";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout<<"\n";

	int to_add = 5;
	std::cout << "Increment: " << to_add << std::endl;

	std::transform(arr, arr+n, arr, increment(to_add)); // добавляет заданное число

	std::cout << "Transform array by functor: ";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	return 0;
}
