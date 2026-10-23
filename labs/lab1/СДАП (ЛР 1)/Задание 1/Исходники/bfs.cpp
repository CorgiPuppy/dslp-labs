// Автор: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей Александрович
// Только одна операция: обход в ширину (BFS)

#include <iostream>
#include <vector>
#include <queue>

class Graph {
    int n;
    std::vector<std::vector<int>> adj;
public:
    Graph(int vertices) : n(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        std::vector<bool> visited(n, false);
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        std::cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u << " ";
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        std::cout << "\n";
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.BFS(0);
    return 0;
}
