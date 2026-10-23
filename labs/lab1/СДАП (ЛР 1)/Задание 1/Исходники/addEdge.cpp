// Автор: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей
// Операция: добавление ребра в граф

#include <iostream>
#include <vector>

class Graph {
    int n;
    std::vector<std::vector<int>> adj;
public:
    Graph(int vertices) : n(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // неориентированный
    }

    void print() {
        for (int i = 0; i < n; i++) {
            std::cout << i << ": ";
            for (int v : adj[i])
                std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    std::cout << "Списки смежности:\n";
    g.print();
    return 0;
}
