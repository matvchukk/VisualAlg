#ifndef HEIGHTDECORATOR_H
#define HEIGHTDECORATOR_H

#include "treenode.h"

/// <summary>
/// Class which adds to a node property "Height" for an AVL tree
/// </summary>
/// <param name="node">pointer to a node which a new property will be signed to</param>
/// <param name="height">height of a given node</param>
template<typename T>
class HeightDecorator : public TreeNode<T> {
private:
    int height;
    TreeNode<T>* node;
public:

    /// <summary>
    /// Asigns height to a given node
    /// </summary>
    /// <param name="node">pointer to a node which a new property will be signed to</param>
    /// <param name="height">height of a given node</param>
    explicit HeightDecorator(TreeNode<T>* node, int height)
        : TreeNode<T>(node->getKey()), node(node), height(height) {
        this->setLeft(node->getLeft());
        this->setRight(node->getRight());
        this->setParent(node->getParent());
    }

    /// <summary>
    /// Gets height of a given node
    /// </summary>
    /// <returns>height of a given node</returns>
    int getHeight() const;
    /// <summary>
    /// Sets height of a given node
    /// </summary>
    /// <param name="height">height of a given node</param>
    void setHeight(int height) const;
};


#endif // HEIGHTDECORATOR_H
