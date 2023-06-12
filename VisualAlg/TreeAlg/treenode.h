#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
class TreeNode {
    T key;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;
public:
    explicit TreeNode(const T value)
        : key(value), left(nullptr), right(nullptr), parent(nullptr) {}

    T getKey() const;
    TreeNode<T>* getLeft() const;
    TreeNode<T>* getRight() const;
    TreeNode<T>* getParent() const;

    void setKey(T value) const;
    void setLeft(TreeNode<T>* leftSon) const;
    void setRight(TreeNode<T>* rightSon) const;
    void setParent(TreeNode<T>* toBeParent) const;
};

#endif  // TREENODE_H
