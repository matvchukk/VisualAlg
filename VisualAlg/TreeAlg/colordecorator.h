#ifndef COLORDECORATOR_H
#define COLORDECORATOR_H

#include "treenode.h"

template<typename T>
class ColorDecorator : public TreeNode<T> {
private:
    TreeNode<T>* node;
    bool color; // red - 0, black - 1

public:
    explicit ColorDecorator(TreeNode<T>* node, bool color)
        : TreeNode<T>(node->getKey()), node(node), color(color) {
        this->setLeft(node->getLeft());
        this->setRight(node->getRight());
        this->setParent(node->getParent());
    }

    bool getColor() const;
    void setColor(bool color) const;
};

#endif // COLORDECORATOR_H
