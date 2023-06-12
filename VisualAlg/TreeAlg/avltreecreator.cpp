#include "avltreecreator.h"

template <typename T>
Tree<T>* AVLTreeCreator<T>::createTree(QList<T> data) const {
    AVLTree<T>* tree = new AVLTree<T>();
    for(int i = 0; i < data.length(); i++)
        tree->insert(&data[i]);

    return tree;
}

