/* main.cpp
 * Автор: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович
 * СДАП Лабораторная работа 10
 * Язык: C++
 */
#include <iostream>
#include <fstream>
#include <locale>

int main() {
    int nv, iv, jv; // количество вершин графа
    std::setlocale(LC_ALL, "rus");
    std::ifstream input("../assets/graph_0-15.txt"); // или ../assets/digraph_0-7.txt
    bool isDirected = false; // true для ориентированного графа

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
        if (!isDirected) {
            A[jv][iv] = 1; // отмечаю 1 вершину (j, i) для неориентированного графа
        }
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

    // подготовка матрицы смежности nxn и запись -1 в список смежности
    for (int i = 0; i < nv; i++)
        for (int j = 0; j < nv; j++)
            AdjList[i][j] = -1;

    // запись вершин в список смежности
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

    // --- Задание 2(2): поиск вершин с наибольшим числом соседей и максимальной степенью ---
    int *outDeg = new int[nv];
    int *inDeg = new int[nv];
    int *deg = new int[nv];
    for (int i = 0; i < nv; i++) {
        outDeg[i] = 0;
        inDeg[i] = 0;
        deg[i] = 0;
    }

    for (int i = 0; i < nv; i++) {
        for (int j = 0; j < nv; j++) {
            if (A[i][j] != 0) {
                outDeg[i]++;
                inDeg[j]++;
            }
        }
    }

    for (int i = 0; i < nv; i++) {
        deg[i] = isDirected ? (inDeg[i] + outDeg[i]) : outDeg[i];
    }

    int maxNeighbors = 0;
    int maxDegree = 0;
    for (int i = 0; i < nv; i++) {
        if (!isDirected) {
            if (outDeg[i] > maxNeighbors) maxNeighbors = outDeg[i];
        } else {
            if (outDeg[i] > maxNeighbors) maxNeighbors = outDeg[i];
            if (inDeg[i] > maxNeighbors) maxNeighbors = inDeg[i];
        }
        if (deg[i] > maxDegree) maxDegree = deg[i];
    }

    std::cout << std::endl;
    if (!isDirected) {
        std::cout << "Наибольшее количество соседей (" << maxNeighbors << ") у вершин: ";
        for (int i = 0; i < nv; i++)
            if (outDeg[i] == maxNeighbors) std::cout << i << " ";
        std::cout << std::endl;

        std::cout << "Максимальная степень (" << maxDegree << ") у вершин: ";
        for (int i = 0; i < nv; i++)
            if (deg[i] == maxDegree) std::cout << i << " ";
        std::cout << std::endl;
    } else {
        std::cout << "Наибольшее число исходящих соседей (" << maxNeighbors << "): ";
        for (int i = 0; i < nv; i++)
            if (outDeg[i] == maxNeighbors) std::cout << i << " ";
        std::cout << std::endl;

        int maxIn = 0;
        for (int i = 0; i < nv; i++)
            if (inDeg[i] > maxIn) maxIn = inDeg[i];
        std::cout << "Наибольшее число входящих соседей (" << maxIn << "): ";
        for (int i = 0; i < nv; i++)
            if (inDeg[i] == maxIn) std::cout << i << " ";
        std::cout << std::endl;

        std::cout << "Максимальная степень (" << maxDegree << ") у вершин: ";
        for (int i = 0; i < nv; i++)
            if (deg[i] == maxDegree) std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}
