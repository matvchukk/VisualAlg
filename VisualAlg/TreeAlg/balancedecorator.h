#ifndef BALANCEDECORATOR_H
#define BALANCEDECORATOR_H

#include "treenode.h"

template<typename T>
class BalanceDecorator : public TreeNode<T> {
private:
    TreeNode<T>* node;
    int balance; // -1 - left is higher, 0 - equal, 1 - right is higher

public:
    explicit BalanceDecorator(TreeNode<T>* node, bool color)
        : TreeNode<T>(node->getKey()), node(node), balance(balance) {
        this->setLeft(node->getLeft());
        this->setRight(node->getRight());
        this->setParent(node->getParent());
    }

    int getBalance() const;
    void setBalance(int balance) const;
};

#endif // BALANCEDECORATOR_H
