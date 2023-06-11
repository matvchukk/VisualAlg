#ifndef AVLTREE_H
#define AVLTREE_H

#include "tree.h"
#include "heightdecorator.h"

template<typename T>
class AVLTree : public Tree<T> {
private:
    HeightDecorator<T>* root;

    int getHeight(HeightDecorator<T>* node) const;
    void fixHeight(HeightDecorator<T>* node);

    int getBalance(HeightDecorator<T>* node) const;
    HeightDecorator<T>* rotateRight(HeightDecorator<T>* node) override;
    HeightDecorator<T>* rotateLeft(HeightDecorator<T>* node) override;

    HeightDecorator<T>* balance(HeightDecorator<T>* node);
    HeightDecorator<T>* insertHelper(HeightDecorator<T>* node, const T& key);
    HeightDecorator<T>* findMin(HeightDecorator<T>* node) const;
    HeightDecorator<T>* removeMin(HeightDecorator<T>* node);
    HeightDecorator<T>* removeHelper(HeightDecorator<T>* node, const T& key);

public:
    AVLTree() : Tree<T>() {}

    void insert(const T& key) override;
    void remove(const T& key) override;
    bool search(const T& key) const override;
};


#endif  // AVLTREE_H
