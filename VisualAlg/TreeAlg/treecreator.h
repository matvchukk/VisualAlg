#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "tree.h"
#include <QList>

template <typename T>
class TreeCreator
{
public:
    virtual ~TreeCreator(){};
    virtual Tree<T>* createTree(QList<T> data) const = 0;
};

#endif // TREECREATOR_H
