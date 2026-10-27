// pairSTL.cpp
// C++ программа для иллюстрации контейнера pair STL
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <iostream>
#include <utility>
#include <string>

int main() {
	// определение и инициализация пар
	std::pair<std::string, int> g1;
	std::pair<std::string, int> g2("Quiz", 3);
	std::pair<std::string, int> g3(g2);
	std::pair<int, int> g4(5, 10);

	g1 = std::make_pair(std::string("Site"), 1);
	g2.first = ".com";
	g2.second = 2;

	std::cout << "Pair g1 = (" << g1.first << ", " << g1.second << ")" << std::endl << std::endl;
	std::cout << "Pair g2 = (" << g2.first << ", " << g2.second << ")" << std::endl << std::endl;

	std::cout << "Pair g3 = (" << g3.first << ", " << g3.second << ").\n" << "\tThis pair was created as a copy of the g2 pair." << std::endl << std::endl;

	std::cout << "Pair g2 = (" << g2.first << ", " << g2.second << ").\n" << "\tThe value of this pair has been changed since initialization." << std::endl << std::endl;

	std::cout << "Pair g4 = (" << g4.first << ", " << g4.second << ").\n" << "\tSum of key and value pair g4 =" << g4.first + g4.second << "." << std::endl << std::endl;

	std::cout << "Let\'s find the concatenation of the symbolic keys of the pairs g1, g2 и g3:\n" << g1.first + g3.first + g2.first << std::endl << std::endl;

	std::cout << "You can change pairs, but their type must be the same:" << std::endl;
	std::cout << "\tBefore the exchange of pairs:\n" << "\t\tg1 = ("<< g1.first << ", "<<g1.second<<")\n " << "\t\tg2 = (" << g2.first << ", " << g2.second << ")" << std::endl;

	// обмен элементами
	std::swap(g1, g2);
	std::cout << "\tAfter the exchange:\n" << "\t\tg1 = ("<< g1.first << ", " << g1.second << ")\n" << "\t\tg2 = (" << g2.first <<", " << g2.second << ")"<< std::endl;

	return 0;
}
