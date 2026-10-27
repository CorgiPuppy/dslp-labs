// testSet1.cpp
// C++ программа-пример операций на множествах
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>

// для удобства объявления
typedef std::set<int> settype;

// переопределение операций
settype operator* (const settype &S, const settype &T ) {
	settype I; // пересечение множеств
	set_intersection(S.begin(),S.end(), T.begin(),T.end(), inserter(I,I.begin()));
	return I;
}

settype operator+ (const settype &S, const settype &T ) {
	settype U;	// объединение множеств
	set_union(S.begin(),S.end(),
				T.begin(),T.end(),
				inserter(U,U.begin()));
	return U;
}

// функция вывода множества
void out_set(const char *set_name, settype S) {
	std::cout << " " << set_name;
	std::copy(S.begin(), S.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

int main() {
	int aS[3] = {10, 20, 30}, aT[4] = {20, 30, 40, 50}; // массивы исходных данных
	settype S(aS, aS + 3), T(aT, aT + 4); // создать множества

	std::cout << "Input sets:\n";
	out_set("\tS = ", S);
	out_set("\tT = ", T);

	std::cout << "Intesection sets S and T:\n";
	out_set("\tS * T = ", S * T);

	std::cout <<"Union sets S and T:\n";
	out_set("\tS + T = ", S + T);

	return 0;
}
