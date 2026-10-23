// Автор: Студент группы ЗОМ34-ПВШ261 Золотухин Андрей
// Операция: in-order обход (сортировка BST)

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

void inorder(Node* n) {
    if (!n) return;
    inorder(n->left);
    std::cout << n->key << " ";
    inorder(n->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    std::cout << "In-order: ";
    inorder(root);
    std::cout << "\n";
    return 0;
}
