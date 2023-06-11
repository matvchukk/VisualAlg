#ifndef AVLTREECREATOR_H
#define AVLTREECREATOR_H

#include "treecreator.h"
#include "avltree.h"

template <typename T>
class AVLTreeCreator : public TreeCreator<T>
{
public:
    Tree<T>* createTree(QList<T> data) const override;
};

#endif // AVLTREECREATOR_H
