#ifndef HEIGHTDECORATOR_H
#define HEIGHTDECORATOR_H

#include "treenode.h"

template<typename T>
class HeightDecorator : public TreeNode<T> {
private:
    int height;
    TreeNode<T>* node;
public:

    explicit HeightDecorator(TreeNode<T>* node, bool color)
        : TreeNode<T>(node->getKey()), node(node), height(height) {
        this->setLeft(node->getLeft());
        this->setRight(node->getRight());
        this->setParent(node->getParent());
    }

    int getHeight() const;
    void setHeight(int height) const;
};


#endif // HEIGHTDECORATOR_H
