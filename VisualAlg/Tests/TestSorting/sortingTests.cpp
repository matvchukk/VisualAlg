#define DOCTEST_CONFIG_IMPLEMENT//_WITH_MAIN
#include "Tests\doctest.h"
#include "SortingAlg\Sorts\bubbleSort.h"
#include "SortingAlg\Sorts\selectionSort.h"
#include "SortingAlg\Sorts\quickSort.h"
#include "SortingAlg\List\list.h"

TEST_CASE("Bubble Sort Test") {
    SUBCASE("Empty List") {
        List list;
        Sort* bubbleSort= new BubbleSort(&list);
        bubbleSort->sort();
        CHECK(list.getSize() == 0);
    }

    SUBCASE("Sorted List") {
        List list;

        list.addItem(1);
        list.addItem(2);
        list.addItem(3);
        list.addItem(4);

        Sort* bubbleSort= new BubbleSort(&list);
        bubbleSort->sort();

        CHECK(list.isListSorted());
    }

    SUBCASE("Unsorted List") {
        List list;
        list.addItem(3);
        list.addItem(2);
        list.addItem(4);
        list.addItem(1);

        Sort* bubbleSort= new BubbleSort(&list);
        bubbleSort->sort();

        CHECK(list.isListSorted());
    }

}


TEST_CASE("Quick Sort Test") {
    SUBCASE("Empty List") {
        List list;
        Sort*  quickSort= new QuickSort(&list);
        quickSort->sort();

        CHECK(list.getSize() == 0);
    }

    SUBCASE("Sorted List") {
        List list;

        list.addItem(1);
        list.addItem(23);
        list.addItem(32);
        list.addItem(45);

        Sort*  quickSort= new QuickSort(&list);
        quickSort->sort();

        CHECK(list.isListSorted());
    }

    SUBCASE("Unsorted List") {
        List list;

        list.addItem(76);
        list.addItem(1);
        list.addItem(12);
        list.addItem(5);

        Sort*  quickSort= new QuickSort(&list);
        quickSort->sort();


        CHECK(list.isListSorted());
    }
}

TEST_CASE("Selection Sort Test") {
    SUBCASE("Empty List") {
        List list;
        Sort* selectionSort= new  SelectionSort(&list);
        selectionSort->sort();

        CHECK(list.getSize() == 0);
    }

    SUBCASE("Sorted List") {
        List list;

        list.addItem(11);
        list.addItem(22);
        list.addItem(33);
        list.addItem(44);

        Sort* selectionSort= new  SelectionSort(&list);
        selectionSort->sort();

        CHECK(list.isListSorted());
    }

    SUBCASE("Unsorted List") {
        List list;

        list.addItem(38);
        list.addItem(26);
        list.addItem(43);
        list.addItem(12);

        Sort* selectionSort= new  SelectionSort(&list);
       selectionSort->sort();

        CHECK(list.isListSorted());
    }
    SUBCASE("Unsorted List") {
        List list;
        list.addItem(38);
        Sort* selectionSort= new  SelectionSort(&list);
       selectionSort->sort();

        CHECK(list.isListSorted());
    }

}
