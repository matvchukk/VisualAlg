#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include <stack>
#include "treenode.h"

/// <summary>
/// Class which makes inorder traversal of a tree
/// </summary>
/// <param name="root">root of a tree to get around</param>
/// <param name="nodeStack">stack of nodes to be visited</param>
template<typename T>
class TreeIterator {
private:
    TreeNode<T>* root;
    std::stack<TreeNode<T>*> nodeStack;

    void pushLeftNodes(TreeNode<T>* node);
public:
    /// <summary>
    /// Start of a traversal
    /// </summary>
    /// <param name="root">root of a tree to get around</param>
    TreeIterator(TreeNode<T>* root) : root(root) {
        pushLeftNodes(root);
    }

    /// <summary>
    /// Finds out if there is unvisited node left in this tree
    /// </summary>
    /// <returns>if there is next node in a tree</returns>
    bool hasNext() const;
    /// <summary>
    /// Makes traversal step
    /// </summary>
    /// <retunrs>key value of a next visited node</returns>
    T next();
};

#endif // TREEITERATOR_H
