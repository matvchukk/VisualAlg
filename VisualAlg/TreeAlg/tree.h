#ifndef TREE_H
#define TREE_H

#include "treenode.h"

template<typename T>
class Tree {
protected:
    TreeNode<T>* root;

    virtual TreeNode<T>* rotateLeft(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* rotateRihgt(TreeNode<T>* node) = 0;
public:
    Tree() : root(nullptr) {}

    virtual void insert(const T& key) = 0;
    virtual void remove(const T& key) = 0;
    virtual bool search(const T& key) const = 0;
};

#endif  // TREE_H
