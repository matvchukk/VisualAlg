#ifndef AVLTREECREATOR_H
#define AVLTREECREATOR_H

#include "treecreator.h"
#include "avltree.h"

template <typename T>
class AVLTreeCreator : public TreeCreator<T>
{
public:
    Tree<T>* createTree() const override {
        return new AVLTree<T>();
    }
};

#endif // AVLTREECREATOR_H
