#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include <stack>
#include "treenode.h"

template<typename T>
class TreeIterator {
private:
    TreeNode<T>* root;
    std::stack<TreeNode<T>*> nodeStack;

    void pushLeftNodes(TreeNode<T>* node);
public:
    TreeIterator(TreeNode<T>* root) : root(root) {
        pushLeftNodes(root);
    }

    bool hasNext() const;
    T next();
};

#endif // TREEITERATOR_H
