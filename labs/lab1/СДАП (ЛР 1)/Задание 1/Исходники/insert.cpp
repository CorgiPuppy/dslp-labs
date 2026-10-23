// Автор: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей
// Только одна операция: вставка в бинарное дерево поиска

#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);

    std::cout << "Корень: " << root->key << "\n";
    std::cout << "Левый потомок: " << root->left->key << "\n";
    std::cout << "Правый потомок: " << root->right->key << "\n";
    return 0;
}
