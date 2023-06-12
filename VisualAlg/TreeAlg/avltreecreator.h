#ifndef AVLTREECREATOR_H
#define AVLTREECREATOR_H

#include "treecreator.h"
#include "avltree.h"

/// <summary>
/// Class which creates a new AVL tree object
/// </summary>
template <typename T>
class AVLTreeCreator : public TreeCreator<T>
{
public:
    /// <summary>
    /// Creates an AVL tree from a list of values
    /// </summary>
    /// <param name="data">a list of values to form a tree</param>
    /// <returns>pointer to the created AVL tree</returns>
    Tree<T>* createTree(QList<T> data) const override;
};

#endif // AVLTREECREATOR_H
