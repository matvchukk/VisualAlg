#ifndef TREE_H
#define TREE_H

#include <QObject>
#include "treenode.h"

/// <summary>
/// Class of trees
///
/// <param name="root">pointer to tree's root</param>
/// </summary>
template<typename T>
class Tree : public QObject {
protected:
    TreeNode<T>* root;

    virtual TreeNode<T>* rotateLeft(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* rotateRihgt(TreeNode<T>* node) = 0;
public:
    /// <summary>
    /// Creates an empty tree
    /// </summary>
    Tree() : root(nullptr) {}

    /// <summary>
    /// Inserts given value to the tree
    /// </summary>
    /// <param name="key">a value to be inserted</param>
    virtual void insert(const T& key) = 0;
    /// <summary>
    /// Delets given value to the tree
    /// </summary>
    /// <param name="key">a value to be deleted</param>
    virtual void remove(const T& key) = 0;
    /// <summary>
    /// Searches given value to the tree
    /// </summary>
    /// <param name="key">a value to be searched</param>
    /// <returns>boolean value which shows if the value is present in the tree</returns>
    virtual bool search(const T& key) const = 0;

};

#endif  // TREE_H
