// Автор: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей
// Операция: поиск в бинарном дереве

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

Node* search(Node* root, int key) {
    if (!root || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 40);

    Node* found = search(root, 40);
    if (found)
        std::cout << "Найден: " << found->key << "\n";
    else
        std::cout << "Не найден\n";

    found = search(root, 99);
    if (found)
        std::cout << "Найден: " << found->key << "\n";
    else
        std::cout << "Не найден\n";

    return 0;
}
