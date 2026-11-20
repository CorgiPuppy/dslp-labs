// summator.cpp
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович
// C++ программа

#include <iostream>
#include <locale>

class summator {
	// данные (св-во)
	private:
		int acc = 0;
	
	// методы
	public:
		void set_acc(int n) { acc = n; } // установит значение сумматора
		int get_acc() { return acc; } // извлечь значение сумматора
		void add(int n) { acc += n; } // прибавить число к сумматору
		void show() { std::cout << "acc value = " << acc << std::endl; } // вывести состояние сумматора
		summator() { acc = 0; } // конструктор по умолчанию
};

int main() {
	setlocale(LC_ALL, "Russian");

	summator d; // создать объект d класса сумматор

	std::cout << "Состояние св-ва объекта сумматор:" << std::endl;
	d.show(); // значение при создании объекта

	d.set_acc(5); 
	d.show(); // значение при установке св-ва

	d.add(10);
	d.show(); // значение при добавлении значения

	d.add(2 * d.get_acc());
	d.show(); // значение при использовании формулы acc := acc + 2 * acc

	return 0;
}
