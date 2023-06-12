#include "treeiterator.h"

template <typename T>
void TreeIterator<T>::pushLeftNodes(TreeNode<T>* node) {
    while (node != nullptr) {
        nodeStack.push(node);
        node = node->getLeft();
    }
}

template <typename T>
bool TreeIterator<T>::hasNext() const {
    return !nodeStack.empty();
}

template <typename T>
T TreeIterator<T>::next() {
    if (!hasNext()) return;

    TreeNode<T>* current = nodeStack.top();
    nodeStack.pop();

    pushLeftNodes(current->getRight());

    return current->getKey();
}
