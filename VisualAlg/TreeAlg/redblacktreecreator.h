#ifndef REDBLACKTREECREATOR_H
#define REDBLACKTREECREATOR_H

#include "treecreator.h"
#include "redblacktree.h"

template <typename T>
class RedBlackTreeCreator : public TreeCreator<T>
{
public:
    Tree<T>* createTree() const override {
        return new RedBlackTree<T>();
    }
};

#endif // REDBLACKTREECREATOR_H
