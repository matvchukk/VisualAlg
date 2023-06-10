#include "treenode.h"

template <typename T>
T TreeNode<T>::getKey() const {
    return key;
}

template <typename T>
TreeNode<T>* TreeNode<T>::getLeft() const {
    return left;
}

template <typename T>
TreeNode<T>* TreeNode<T>::getRight() const {
    return right;
}

template <typename T>
TreeNode<T>* TreeNode<T>::getParent() const {
    return parent;
}

template <typename T>
void TreeNode<T>::setKey(T value) const {
    key = value;
}

template <typename T>
void TreeNode<T>::setLeft(TreeNode<T>* leftSon) const {
    left = leftSon;
}

template <typename T>
void TreeNode<T>::setRight(TreeNode<T>* rightSon) const {
    right = rightSon;
}

template <typename T>
void TreeNode<T>::setParent(TreeNode<T>* toBeParent) const {
    parent = toBeParent;
}
