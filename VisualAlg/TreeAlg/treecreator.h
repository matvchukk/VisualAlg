#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "tree.h"

template <typename T>
class TreeCreator
{
public:
    virtual ~TreeCreator(){};
    virtual Tree<T>* createTree() const = 0;
};

#endif // TREECREATOR_H
