# digraphs.py
# Автор: студент группы ЗОМ34-ПВШ2616 Золотухин Андрей Александрович

'''
Программа создаёт и выводит изображение ориентированного графа
'''

import networkx as nx
import matplotlib.pyplot as plt

G = nx.DiGraph() # создание пустого ориентированного графа
edges = [(1, 2), (1, 3), (2, 3), (3, 4), (4, 5), (5, 1), (5, 6), (6, 1)] # список кортежей
G.add_edges_from(edges) # добавление рёбер в класс G ориентированного графа

nx.draw(G, with_labels=True, arrowsize=20)
plt.savefig('../assets/digraphs.png')
