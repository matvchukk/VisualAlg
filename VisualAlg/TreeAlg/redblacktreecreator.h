#ifndef REDBLACKTREECREATOR_H
#define REDBLACKTREECREATOR_H

#include "treecreator.h"
#include "redblacktree.h"

template <typename T>
class RedBlackTreeCreator : public TreeCreator<T>
{
public:
    Tree<T>* createTree(QList<T> data) const override;
};

#endif // REDBLACKTREECREATOR_H
