// Stack.cpp
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей
// Язык: C++. Иллюстрирует работу такой структуры данных как Стек

#include <iostream>
#include <stack>

int main() {
	// значения, помещенные в стек,
	// должны содержать те же данные, которые записаны во время объявления стека
	std::stack<int> stack; // стек целочисленных данных

	// Заменил ручное добавление в цикл и поменял значения стека немного
	for (int i = 21; i <= 25; i++) {
		stack.push(i); // добавить значение в стек

		// Stack top
    std::cout << " Top = " << stack.top() << std::endl;
	}

	int number = 0;
	stack.push(number);
	std::cout << " Top = " << stack.top() << std::endl; // заголовок стека

  std::cout << " Размер стека = " << stack.size() << std::endl;
	std::cout << " Содержимое стека: ";
	while (!stack.empty()) {
		std::cout << stack.top() << " ";

		// Удаляем элемент стека
		stack.pop();
	}
	std::cout << std::endl;
	if (stack.empty()) // стек пуст?
		std::cout << " Stack is empty." << std::endl;
	else std::cout << " Stack is not empty." << std::endl;
}

