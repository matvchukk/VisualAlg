#ifndef COLORDECORATOR_H
#define COLORDECORATOR_H

#include "treenode.h"

/// <summary>
/// Class which adds to a node property "Color" for a Red-Black tree
/// </summary>
/// <param name="node">pointer to a node which a new property will be signed to</param>
/// <param name="color">boolean value of node's color: 1 is red, 0 is black</param>
template<typename T>
class ColorDecorator : public TreeNode<T> {
private:
    TreeNode<T>* node;
    bool color; // red - 1, black - 0

public:
    /// <summary>
    /// Asigns color to a given node
    /// </summary>
    /// <param name="node">pointer to a node which a new property will be signed to</param>
    /// <param name="color">boolean value of node's color: 1 is red, 0 is black</param>
    explicit ColorDecorator(TreeNode<T>* node, bool color)
        : TreeNode<T>(node->getKey()), node(node), color(color) {
        this->setLeft(node->getLeft());
        this->setRight(node->getRight());
        this->setParent(node->getParent());
    }

    /// <summary>
    /// Gets color of a given node
    /// </summary>
    /// <returns>boolean value of this node's color: 1 is red, 0 is black</returns>
    bool getColor() const;
    /// <summary>
    /// Sets color of a given node
    /// </summary>
    /// <param name="color">boolean value of node's color: 1 is red, 0 is black, to be asigned</param>
    void setColor(bool color) const;
};

#endif // COLORDECORATOR_H
