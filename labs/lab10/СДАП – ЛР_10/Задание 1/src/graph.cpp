// graph.cpp
// Автор ОЗНАКОМЛЕН: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович
// C++ программа задает неориентированный и ориентированный граф в виде матрицы смежности и списка смежности
#include <iostream>
#include <fstream>
#include <locale>

int main() {
	int nv, iv, jv; // количество вершин графа
	std::setlocale(LC_ALL, "rus");
	std::ifstream input("../assets/graph2.txt"); // читаю данные из входного потока
	// или graph1.txt
	input >> nv;
	std::cout << "Количество вершин графа: " << "n = " << nv << std::endl;
	int **A = new int *[nv]; // матрица смежности
	for (int i = 0; i < nv; i++)
		A[i] = new int[nv];
	
	// подготовлю матрицу смежности nxn и записываю 0 в матрицу и список смежности
	for (int i = 0; i < nv; i++)
		for (int j = 0; j < nv; j++)
			A[i][j] = 0;
	// читаю номера вершин, соединённые ребром
	while (!input.eof()) {
		input >> iv >> jv;
		A[iv][jv] = 1; // отмечаю 1 вершину (i, j)
		A[jv][iv] = 1; // отмечаю 1 вершину (j, i)
	}
	input.close(); // закрываю поток ввода
	std::cout << std::endl;
	
	// Вывод матрицы смежности
	std::cout << "Матрица смежности графа:" << std::endl;
	for (int i = 0; i < nv; i++) {
		for (int j = 0; j < nv; j++)
			std::cout << A[i][j] << " ";
		std::cout << std::endl;
	}
	
	// Формирование списка смежности
	int **AdjList = new int*[nv];
	for (int i = 0; i < nv; i++)
		AdjList[i] = new int[nv];
	
	// подготовка матрицы смежности nxn и запись -1 в матрицу и список смежности
	for (int i = 0; i < nv; i++)
		for (int j = 0; j < nv; j++)
			AdjList[i][j] = -1;
	// запись вершин в список смежности
	//
	for (int i = 0; i < nv; i++)
		for (int j = 0; j < nv; j++)
			if (A[i][j] != 0) AdjList[i][j] = j;
	// Вывод
	std::cout << "Список смежности графа:" << std::endl;
	for (int i = 0; i < nv; i++) {
		std::cout << i << ": ";
		for (int j = 0; j < nv; j++)
			if (AdjList[i][j] != -1) std::cout << AdjList[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << "Список путей графа:" << std::endl;
	for (int i = 0; i < nv; i++) {
		std::cout << "Вершины: " << i;
		for (int j = 0; j < nv; j++)
			if (AdjList[i][j] != -1) std::cout << " <---> " << AdjList[i][j];
		std::cout << std::endl;
	}
	return 0;
}
