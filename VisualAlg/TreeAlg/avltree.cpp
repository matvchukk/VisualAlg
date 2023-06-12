#include "avltree.h"

template<typename T>
int AVLTree<T>::getHeight(HeightDecorator<T>* node) const {
    return node ? 1 + max(node->getLeft()->getHeight(), node->getRight()->getHeight()) : 0;
}

template <typename T>
int AVLTree<T>::getBalance(HeightDecorator<T>* node) const{
    if (!node) return 0;
    if (!node->getLeft() && !node->getRight()) return 0;
    if (!node->getLeft()) return node->getRight()->getHeight;
    if (!node->getRight()) return -1 * node->getLeft()->getHeight;

    return node->getRight()->getHeight() - node->getLeft()->getHeight();
}

template<typename T>
void AVLTree<T>::fixHeight(HeightDecorator<T>* node) {
    int heightLeft = node->getLeft()->getHeight();
    int heightRight = node->getRight()->getHeight();
    node->setHeight(1 + max(heightLeft, heightRight));
}

template<typename T>
HeightDecorator<T>* AVLTree<T>::rotateRight(HeightDecorator<T>* node) {
    HeightDecorator<T>* pivot = node->getLeft();
    node->setLeft(pivot->getRight());
    pivot->setRight(node);
    fixHeight(node);
    fixHeight(pivot);
    return pivot;
}

template<typename T>
HeightDecorator<T>* AVLTree<T>::rotateLeft(HeightDecorator<T>* node) {
    HeightDecorator<T>* pivot = node->getRight();
    node->setRight(pivot->getLeft());
    pivot->setLeft(node);
    fixHeight(node);
    fixHeight(pivot);
    return pivot;
}

template<typename T>
HeightDecorator<T>* AVLTree<T>::balance(HeightDecorator<T>* node) {
    fixHeight(node);
    if (getBalance(node) == 2) {
        if (getBalance(node->getRight()) < 0)
            node->setRight(rotateRight(node->getRight()));
        return rotateLeft(node);
    }
    if (getBalance(node) == -2) {
        if (getBalance(node->getLeft()) > 0)
            node->setLeft(rotateLeft(node->getLeft()));
        return rotateRight(node);
    }
    return node;
}

template<typename T>
HeightDecorator<T>* AVLTree<T>::insertHelper(HeightDecorator<T>* node, const T& key) {
    if (!node)
        return new HeightDecorator<T>(key);
    if (key < node->key)
        node->setLeft(insertHelper(node->getLeft(), key));
    else
        node->setRight(insertHelper(node->getRight(), key));
    return balance(node);
}

template<typename T>
void AVLTree<T>::insert(const T& key) {
    this->root = insertHelper(this->root, key);
}

template<typename T>
HeightDecorator<T>* AVLTree<T>::findMin(HeightDecorator<T>* node) const {
    return node->getLeft() ? findMin(node->getLeft()) : node;
}

template<typename T>
HeightDecorator<T>* AVLTree<T>::removeMin(HeightDecorator<T>* node) {
    if (node->getLeft() == nullptr)
        return node->getRight();
    node->setLeft(removeMin(node->getLeft()));
    return balance(node);
}

template<typename T>
HeightDecorator<T>* AVLTree<T>::removeHelper(HeightDecorator<T>* node, const T& key) {
    if (!node)
        return nullptr;
    if (key < node->key)
        node->setLeft(removeHelper(node->getLeft(), key));
    else if (key > node->key)
        node->setRight(removeHelper(node->getRight(), key));
    else {
        HeightDecorator<T>* leftChild = node->left;
        HeightDecorator<T>* rightChild = node->right;
        delete node;
        if (!rightChild)
            return leftChild;
        HeightDecorator<T>* minNode = findMin(rightChild);
        minNode->setRight(removeMin(rightChild));
        minNode->setLeft(leftChild);
        return balance(minNode);
    }
    return balance(node);
}

template<typename T>
void AVLTree<T>::remove(const T& key) {
    this->root = removeHelper(this->root, key);
}

template<typename T>
bool AVLTree<T>::search(const T& key) const {
    HeightDecorator<T>* currentNode = this->root;
    while (currentNode) {
        if (key < currentNode->key)
            currentNode = currentNode->left;
        else if (key > currentNode->key)
            currentNode = currentNode->right;
        else
            return true;
    }
    return false;
}
