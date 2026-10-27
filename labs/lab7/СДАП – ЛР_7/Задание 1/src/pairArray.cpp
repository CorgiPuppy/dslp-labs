// pairArray.cpp
// C++ программа для создания пар всех чётных чисел, присутствующих в заданном массиве
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

/* Для заданного  целочисленного массива вывести все пары,
 * которые содержат четные числа. Если пар четных чисел нет,
 * то вывести -1.
 */

#include <iostream>
#include <vector>

// замена, чтобы не писать очень длинный тип данных
typedef std::pair<int, int> pairs;

// функция для вывода массива пар
void display_pairs(const std::vector<pairs>& s){
	bool found = false;

	 // вывести, если есть элементы в массиве
	for (int i = 0; i < s.size(); i++) {
		found = true;
		std::cout << "(" << s[i].first << ", "
				 << s[i].second << ")"
				 << " ";
	}

	// в массиве нет элементов 
	// (по идее не вызовется никогда, так как мы это проверяем ещё в main. То есть мы вызываем эту функцию только когда чётные числа существуют, чтобы отобразить эти пары)
	if (not found)
			std::cout << "There are no pairs of even numbers in the array.\n ";
}

int main() {
	int data;
	std::vector<int> v;
	std::vector<pairs> s;

	std::cout << "Enter numbers via spaces: "; // добавил информацию о том, что ждёт программа от пользователя
	// ввод строки данных из потока до конца строки
	while (std::cin.peek() != '\n') {
		std::cin >> data;
		v.push_back(data);
	}

	// анализ данных
	bool even_numbers = false;
	for (int i = 0; i < v.size(); i++) { // исправил проход до v.size()-1 вместо v.size()-2
		for (int j = i; j < v.size(); j++) { // исправил инициализацию j как i вместо i+1, чтобы затрагивать одинаковые чётные числа (типа 2,2 или 4,4, не упуская их, так как это тоже считается парой)
			// проверка чисел на четность
			if (v[i] % 2 == 0 && v[j] % 2 == 0) {
				// создать пару из четных чисел
				pairs x = std::make_pair(v[i], v[j]);
				even_numbers = true;

				// и сохранить в вектор
				s.push_back(x);
			}
		}
	}

	// отобразить результат
	if (even_numbers) {
		std::cout << "Pairs of even numbers: ";	// для понятного вывода	
		display_pairs(s);
		std::cout << std::endl;
	}
	else std::cout << -1 << std::endl;

	// очистить вектор
	s.clear();
}

