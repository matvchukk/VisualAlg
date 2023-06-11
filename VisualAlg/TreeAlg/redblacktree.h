#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "colordecorator.h"
#include "tree.h"

template<typename T>
class RedBlackTree : public Tree<T> {
private:

    ColorDecorator<T>* rotateRight(ColorDecorator<T>* node) override;
    ColorDecorator<T>* rotateLeft(ColorDecorator<T>* node) override;

    void insertFixup(ColorDecorator<T>* node);
    void removeFixup(ColorDecorator<T>* node, ColorDecorator<T>* parentNode);
    ColorDecorator<T>* findSuccessor(ColorDecorator<T>* node) const;

public:
    RedBlackTree() : Tree<T>() {}

    void insert(const T& key) override;
    void remove(const T& key) override;
    bool search(const T& key) const override;
};

#endif  // REDBLACKTREE_H
