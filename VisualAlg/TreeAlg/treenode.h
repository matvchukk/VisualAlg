#ifndef TREENODE_H
#define TREENODE_H

/// <summary>
/// Class of tree's nodes
///
/// <param name="key">key value of a node</param>
/// <param name="left">left son of a node</param>
/// <param name="right">right son of a node</param>
/// <param name="parent">parent of a node</param>
/// </summary>
template<typename T>
class TreeNode {
    T key;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;
public:
    /// <summary>
    /// Creates a tree node with a given pointers and all pointers (left, right, parent) are set as NULL
    /// </summary>
    explicit TreeNode(const T value)
        : key(value), left(nullptr), right(nullptr), parent(nullptr) {}

    /// <summary>
    /// Gets key of a given node
    /// </summary>
    /// <returns>key value of a node</returns>
    T getKey() const;
    /// <summary>
    /// Gets left son of a given node
    /// </summary>
    /// <returns>pointer to the left son of a node</returns>
    TreeNode<T>* getLeft() const;
    /// <summary>
    /// Gets right son of a given node
    /// </summary>
    /// <returns>pointer to the right son of a node</returns>
    TreeNode<T>* getRight() const;
    /// <summary>
    /// Gets parent of a given node
    /// </summary>
    /// <returns>pointer to the parent of a node</returns>
    TreeNode<T>* getParent() const;

    /// <summary>
    /// Sets key of a given node
    /// </summary>
    /// <param name="value">a value to be set as a key</param>
    void setKey(T value) const;
    /// <summary>
    /// Sets left son of a given node
    /// </summary>
    /// <param name="leftSon">a pointer to be set as a left son</param>
    void setLeft(TreeNode<T>* leftSon) const;
    /// <summary>
    /// Sets right son of a given node
    /// </summary>
    /// <param name="rightSon">a pointer to be set as a right son</param>
    void setRight(TreeNode<T>* rightSon) const;
    /// <summary>
    /// Sets parent a given node
    /// </summary>
    /// <param name="toBeParent">a pointer to be set as a parent</param>
    void setParent(TreeNode<T>* toBeParent) const;
};

#endif  // TREENODE_H
