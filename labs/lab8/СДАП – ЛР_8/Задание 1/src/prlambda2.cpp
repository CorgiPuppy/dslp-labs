// prlambda2.cpp
// Лямбда и С++ STL
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

/*
 * Следующий код разобьёт массив из 10-ти натуральных чисел на четные и нечетные числа.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int n = 100;
	std::vector<int> v;
	for (int i = 0; i < n; i = (i % 2 == 0) ? i + 1 : i * 2)
		// разнообразия добавил другую последовательность
		v.push_back(i);

	std::cout << "Array: ";
	// определим функцию вывода чисел из вектора как лямбда-выражение
	for_each(v.begin(), v.end(), [] (int val) {
		 std::cout << val << " ";
	});
	std::cout << std::endl;

	std::cout << "Even: ";
	// определим функцию выбора четных чисел из вектора как лямбда-выражение
	for_each(v.begin(), v.end(), [] (int val) {
		if (val % 2 == 0) std::cout << val << " ";
	});

	std::cout << std::endl << "Odd: ";
	// определим функцию выбора нечетных чисел из вектора как лямбда-выражение
	for_each( v.begin(), v.end(), [] (int val) {
		if (val % 2 == 1) std::cout << val << " ";
	});
	std::cout << std::endl;

	return 0;
}
