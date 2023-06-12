#ifndef AVLTREE_H
#define AVLTREE_H

#include "tree.h"
#include "heightdecorator.h"

/// <summary>
/// Class of AVL trees
///
/// <param name="root">pointer to tree's root</param>
/// </summary>
template<typename T>
class AVLTree : public Tree<T> {
private:
    HeightDecorator<T>* root;

    int getHeight(HeightDecorator<T>* node) const;
    void fixHeight(HeightDecorator<T>* node);

    int getBalance(HeightDecorator<T>* node) const;
    HeightDecorator<T>* rotateRight(HeightDecorator<T>* node) ;
    HeightDecorator<T>* rotateLeft(HeightDecorator<T>* node) ;

    HeightDecorator<T>* balance(HeightDecorator<T>* node);
    HeightDecorator<T>* insertHelper(HeightDecorator<T>* node, const T& key);
    HeightDecorator<T>* findMin(HeightDecorator<T>* node) const;
    HeightDecorator<T>* removeMin(HeightDecorator<T>* node);
    HeightDecorator<T>* removeHelper(HeightDecorator<T>* node, const T& key);

public:
    /// <summary>
    /// Creates an empty AVL tree
    /// </summary>
    AVLTree() : Tree<T>() {}

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


#endif  // AVLTREE_H
