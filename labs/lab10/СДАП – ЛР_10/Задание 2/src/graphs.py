# graphs.py
# чтение файла в список кортежей и отрисовка графа

import networkx as nx
import matplotlib.pyplot as plt

def load_edges(filepath):
    edges = [] # список кортежей
    with open(filepath, "r", encoding="utf-8") as f:
        n = int(f.readline().strip())
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 2:
                u, v = int(parts[0]), int(parts[1])
                edges.append((u, v))
    return n, edges

# Неориентированный граф (graph_0-15)
n_undir, edges_undir = load_edges("../assets/graph_0-15.txt")
G_undir = nx.Graph()
G_undir.add_nodes_from(range(n_undir))
G_undir.add_edges_from(edges_undir) # добавление рёбер из списка кортежей

plt.figure(figsize=(8, 6))
nx.draw(G_undir, with_labels=True, node_color="lightblue", node_size=600)
plt.savefig("../assets/graph_0-15.png")

# Ориентированный граф (digraph_0-7)
n_dir, edges_dir = load_edges("../assets/graph_0-7.txt")
G_dir = nx.DiGraph() # создание пустого ориентированного графа
G_dir.add_nodes_from(range(n_dir))
G_dir.add_edges_from(edges_dir) # добавление рёбер в класс G ориентированного графа

plt.figure(figsize=(8, 6))
nx.draw(G_dir, with_labels=True, arrowsize=20)
plt.savefig("../assets/graph_0-7.png")
