#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "colordecorator.h"
#include "tree.h"

/// <summary>
/// Class of Red-Black trees
///
/// <param name="root">pointer to tree's root</param>
/// </summary>
template<typename T>
class RedBlackTree : public Tree<T> {
private:

    ColorDecorator<T>* rotateRight(ColorDecorator<T>* node) ;
    ColorDecorator<T>* rotateLeft(ColorDecorator<T>* node) ;
    void transplant(ColorDecorator<T>* node1, ColorDecorator<T>* node2);

    void insertFixup(ColorDecorator<T>* node);
    void removeFixup(ColorDecorator<T>* node, ColorDecorator<T>* parentNode);
    ColorDecorator<T>* findSuccessor(ColorDecorator<T>* node) const;

public:
    /// <summary>
    /// Creates an empty Red-Black tree
    /// </summary>
    RedBlackTree() : Tree<T>() {}

    /// <summary>
    /// Inserts given value to the tree
    /// </summary>
    /// <param name="key">a value to be inserted</param>
    void insert(const T& key) override;
    /// <summary>
    /// Delets given value to the tree
    /// </summary>
    /// <param name="key">a value to be deleted</param>
    void remove(const T& key) override;
    /// <summary>
    /// Searches given value to the tree
    /// </summary>
    /// <param name="key">a value to be searched</param>
    /// <returns>boolean value which shows if the value is present in the tree</returns>
    bool search(const T& key) const override;

};

#endif  // REDBLACKTREE_H
