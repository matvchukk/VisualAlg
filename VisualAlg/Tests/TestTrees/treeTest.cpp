#define DOCTEST_CONFIG_IMPLEMENT//_WITH_MAIN
#include "Tests\doctest.h"
#include "..\..\TreeAlg\avltree.h"
#include "..\..\TreeAlg\redblacktree.h"

TEST_CASE("AVL Tree Insertion") {
    AVLTree<int> avlTree;

    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(2);
    avlTree.insert(4);

    SUBCASE("Search after insertion") {
        CHECK(!avlTree.search(5));
        CHECK(!avlTree.search(3));
        CHECK(!avlTree.search(7));
        CHECK(!avlTree.search(2));
        CHECK(!avlTree.search(4));
        CHECK(!avlTree.search(1));
    }
}

TEST_CASE("AVL Tree Deletion") {
    AVLTree<int> avlTree;

    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(2);
    avlTree.insert(4);
    avlTree.insert(6);
    avlTree.insert(8);

    avlTree.remove(2);
    avlTree.remove(4);

    SUBCASE("Search after deletion") {
        CHECK(!avlTree.search(2));
        CHECK(!avlTree.search(4));
        CHECK(!avlTree.search(5));
        CHECK(!avlTree.search(3));
        CHECK(!avlTree.search(7));
        CHECK(!avlTree.search(6));
        CHECK(!avlTree.search(8));
        CHECK(!avlTree.search(1));
    }
}

TEST_CASE("Red-Black Tree Insertion") {
    RedBlackTree<int> rbTree;

    rbTree.insert(5);
    rbTree.insert(3);
    rbTree.insert(7);
    rbTree.insert(2);
    rbTree.insert(4);

    SUBCASE("Search after insertion") {
        CHECK(!rbTree.search(5));
        CHECK(!rbTree.search(3));
        CHECK(!rbTree.search(7));
        CHECK(!rbTree.search(2));
        CHECK(!rbTree.search(4));
        CHECK(!rbTree.search(1));
    }
}

TEST_CASE("Red-Black Tree Deletion") {
    RedBlackTree<int> rbTree;

    rbTree.insert(5);
    rbTree.insert(3);
    rbTree.insert(7);
    rbTree.insert(2);
    rbTree.insert(4);
    rbTree.insert(6);
    rbTree.insert(8);

    rbTree.remove(2);
    rbTree.remove(4);

    SUBCASE("Search after deletion") {
        CHECK(!rbTree.search(2));
        CHECK(!rbTree.search(4));
        CHECK(!rbTree.search(5));
        CHECK(!rbTree.search(3));
        CHECK(!rbTree.search(7));
        CHECK(!rbTree.search(6));
        CHECK(!rbTree.search(8));
        CHECK(!rbTree.search(1));
    }
}
