#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "tree.h"
#include <QList>

/// <summary>
/// Class which creates a new tree object
/// </summary>
template <typename T>
class TreeCreator
{
public:
    virtual ~TreeCreator(){};
    /// <summary>
    /// Creates a tree from a list of values
    /// </summary>
    /// <param name="data">a list of values to form a tree</param>
    /// <returns>pointer to the created tree</returns>
    virtual Tree<T>* createTree(QList<T> data) const = 0;
};

#endif // TREECREATOR_H
