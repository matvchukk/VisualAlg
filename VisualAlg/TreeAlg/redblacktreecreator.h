#ifndef REDBLACKTREECREATOR_H
#define REDBLACKTREECREATOR_H

#include "treecreator.h"
#include "redblacktree.h"

/// <summary>
/// Class which creates a new AVL tree object
/// </summary>
template <typename T>
class RedBlackTreeCreator : public TreeCreator<T>
{
public:
    /// <summary>
    /// Creates a Red-Black tree from a list of values
    /// </summary>
    /// <param name="data">a list of values to form a tree</param>
    /// <returns>pointer to the created Red-Black tree</returns>
    Tree<T>* createTree(QList<T> data) const override;
};

#endif // REDBLACKTREECREATOR_H
