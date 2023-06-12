#include "redblacktreecreator.h"

template <typename T>
Tree<T>* RedBlackTreeCreator<T>::createTree(QList<T> data) const {
    RedBlackTree<T>* tree = new RedBlackTree<T>();
    for(int i = 0; i < data.length(); i++)
        tree->insert(&data[i]);

    return tree;
}
