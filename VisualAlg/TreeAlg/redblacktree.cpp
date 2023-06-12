#include "redblacktree.h"

template <typename T>
void RedBlackTree<T>::transplant(ColorDecorator<T>* node1, ColorDecorator<T>* node2) {
    if (node1->getParent() == nullptr) {
        this->root = node2;
    } else if (node1 == node1->getParent()->getLeft()) {
        node1->getParent()->setLeft(node2);
    } else {
        node1->getParent()->setRight(node2);
    }

    if (node2 != nullptr) {
        node2->setParent(node1->getParent());
    }
}

template<typename T>
ColorDecorator<T>* RedBlackTree<T>::rotateRight(ColorDecorator<T>* node) {
    ColorDecorator<T>* pivot = node->getLeft();
    node->setLeft(pivot->getRight());
    pivot->setRight(node);

    return pivot;
}

template<typename T>
ColorDecorator<T>* RedBlackTree<T>::rotateLeft(ColorDecorator<T>* node) {
    ColorDecorator<T>* pivot = node->getRight();
    node->setRight(pivot->getLeft());
    pivot->setLeft(node);

    return pivot;
}

template<typename T>
void RedBlackTree<T>::insertFixup(ColorDecorator<T>* node) {
    while (node != this->root && node->getParent()->getColor()) {
        if (node->getParent() == node->getParent()->getParent()->getLeft()) {
            ColorDecorator<T>* uncle = node->getParent()->getParent()->getRight();
            if (uncle && uncle->getColor()) {
                node->getParent()->setColor(0);
                uncle->setColor(0);
                node->getParent()->getParent()->setColor(1);
                node = node->getParent()->getParent();
            } else {
                if (node == node->getParent()->getRight()) {
                    node = node->getParent();
                    this->root = this->rotateLeft(node);
                }
                node->getParent()->setColor(0);
                node->getParent()->getParent()->setColor(1);
                this->root = this->rotateRight(node->getParent()->getParent());
            }
        } else {
            ColorDecorator<T>* uncle = node->getParent()->getParent()->getLeft();
            if (uncle && uncle->getColor()) {
                node->getParent()->setColor(0);
                uncle->setColor(0);
                node->getParent()->getParent()->setColor(1);
                node = node->getParent()->getParent();
            } else {
                if (node == node->getParent()->getLeft()) {
                    node = node->getParent();
                    this->root = this->rotateRight(node);
                }
                node->getParent()->setColor(0);
                node->getParent()->getParent()->setColor(1);
                this->root = this->rotateLeft(node->getParent()->getParent());
            }
        }
    }
    this->root->setColor(0);
}

template<typename T>
void RedBlackTree<T>::insert(const T& key) {
    ColorDecorator<T>* newNode = new ColorDecorator<T>(key);
    ColorDecorator<T>* parentNode = nullptr;
    ColorDecorator<T>* currentNode = this->root;
    while (currentNode) {
        parentNode = currentNode;
        if (key < currentNode->getKey())
            currentNode = currentNode->getLeft();
        else
            currentNode = currentNode->getRight();
    }
    newNode->getParent() = parentNode;
    if (!parentNode)
        this->root = newNode;
    else if (key < parentNode->getKey())
        parentNode->getLeft() = newNode;
    else
        parentNode->getRight() = newNode;
    insertFixup(newNode);
}

template<typename T>
void RedBlackTree<T>::removeFixup(ColorDecorator<T>* node, ColorDecorator<T>* parentNode) {
    while (node != this->root && (!node || !node->getColor())) {
        if (node == parentNode->getLeft()) {
            ColorDecorator<T>* sibling = parentNode->getRight();
            if (sibling && sibling->getColor()) {
                sibling->setColor(0);
                parentNode->setColor(1);
                this->root = this->rotateLeft(parentNode);
                sibling = parentNode->getRight();
            }
            if ((!sibling->getLeft() || !sibling->getLeft()->getColor()) && (!sibling->getRight() || !sibling->getRight()->getColor())) {
                sibling->setColor(1);
                node = parentNode;
                parentNode = node ? node->getParent() : nullptr;
            } else {
                if (!sibling->getRight() || !sibling->getRight()->getColor()) {
                    sibling->getLeft()->setColor(0);
                    sibling->setColor(1);
                    this->root = this->rotateRight(sibling);
                    sibling = parentNode->getRight();
                }
                sibling->setColor(parentNode ? parentNode->getColor() : 0);
                parentNode->setColro(0);
                sibling->getRight()->setColor(0);
                this->root = this->rotateLeft(parentNode);
                node = this->root;
                parentNode = node ? node->parent : nullptr;
            }
        } else {
            ColorDecorator<T>* sibling = parentNode->getLeft();
            if (sibling && sibling->getColor()) {
                sibling->setColor(0);
                parentNode->setColor(1);
                this->root = this->rotateRight(parentNode);
                sibling = parentNode->getLeft();
            }
            if ((!sibling->getRight() || !sibling->getRight()->getColor()) && (!sibling->getLeft() || !sibling->getLeft()->getColor())) {
                sibling->setColor(1);
                node = parentNode;
                parentNode = node ? node->parent : nullptr;
            } else {
                if (!sibling->getLeft() || !sibling->getLeft()->getColor()) {
                    sibling->right->setc=Color(0);
                    sibling->setColor(1);
                    this->root = this->rotateLeft(sibling);
                    sibling = parentNode->getLeft();
                }
                sibling->setColor(parentNode ? parentNode->getColor() : 0);
                parentNode->setColor(0);
                sibling->getLeft()->setColor(0);
                this->root = this->rotateRight(parentNode);
                node = this->root;
                parentNode = node ? node->parent : nullptr;
            }
        }
    }
    if (node) node->setcolor(0);
}

template<typename T>
ColorDecorator<T>* RedBlackTree<T>::findSuccessor(ColorDecorator<T>* node) const {
    if (node->getRight()) {
        node = node->getRight();
        while (node->getLeft())
            node = node->getLeft();
    } else {
        ColorDecorator<T>* parentNode = node->getParent();
        while (parentNode && node == parentNode->getRight()) {
            node = parentNode;
            parentNode = parentNode->getParent();
        }
        node = parentNode;
    }
    return node;
}

template<typename T>
void RedBlackTree<T>::remove(const T& key) {
    ColorDecorator<T>* currentNode = this->root;
    while (currentNode) {
        if (key < currentNode->getKey())
            currentNode = currentNode->getLeft();
        else if (key > currentNode->getKey())
            currentNode = currentNode->getRight();
        else
            break;
    }
    if (!currentNode) return;
    ColorDecorator<T>* removeNode = currentNode;
    ColorDecorator<T>* fixupNode = nullptr;
    bool originalColor = removeNode->getColor();
    if (!removeNode->getLeft()) {
        fixupNode = removeNode->getRight();
        this->root = this->transplant(removeNode, removeNode->getRight());
    } else if (!removeNode->getRight()) {
        fixupNode = removeNode->getLeft();
        this->root = this->transplant(removeNode, removeNode->getLeft());
    } else {
        removeNode = findSuccessor(removeNode);
        originalColor = removeNode->getColor();
        fixupNode = removeNode->getRight();
        if (removeNode->getParent() == currentNode)
            fixupNode->setParent(removeNode);
        else {
            this->transplant(removeNode, removeNode->getRight());
            removeNode->setRight(currentNode->getRight());
            removeNode->getRight()->setParent(removeNode);
        }
        this->transplant(currentNode, removeNode);
        removeNode->setLeft(currentNode->getLeft());
        removeNode->getLeft()->setParent(removeNode);
        removeNode->setColor(currentNode->getColor());
    }
    delete currentNode;
    if (!originalColor)
        removeFixup(fixupNode, fixupNode ? fixupNode->getParent() : nullptr);
}

template<typename T>
bool RedBlackTree<T>::search(const T& key) const {
    ColorDecorator<T>* currentNode = this->root;
    while (currentNode) {
        if (key < currentNode->getKey())
            currentNode = currentNode->getLeft();
        else if (key > currentNode->getKey())
            currentNode = currentNode->getRight();
        else
            return true;
    }
    return false;
}
