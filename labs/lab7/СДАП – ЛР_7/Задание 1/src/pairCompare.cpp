// pairCompare.cpp
// C++ программа для сравнения пар чисел
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <iostream>
#include <utility>

// для простоты объявления
typedef std::pair<int, int> pairs;

int main() {
	pairs pair1 = std::make_pair(1, 12);
	pairs pair2 = std::make_pair(9, 12);

	// вывод пар
	std::cout << "Pair pair1 = (" << pair1.first << ", " << pair1.second << ")" << std::endl;
	std::cout << "Pair pair2 = (" << pair2.first << ", " << pair2.second << ")" << std::endl << std::endl;
	
	// все возможные сравнения двух пар
	std::cout << "Comparison (pair1 == pair2)" << " returns " << (pair1 == pair2) << std::endl;
	std::cout << "Comparison (pair1 != pair2)" << " returns " << (pair1 != pair2) << std::endl;
	std::cout << "Comparison (pair1 >= pair2)" << " returns " << (pair1 >= pair2) << std::endl;
	std::cout << "Comparison (pair1 <= pair2)" << " returns " << (pair1 <= pair2) << std::endl;
	std::cout << "Comparison (pair1 > pair2)" << " returns " << (pair1 > pair2) << std::endl;
	std::cout << "Comparison (pair1 < pair2)" << " returns " << (pair1 < pair2) << std::endl;
	
	return 0;
}
