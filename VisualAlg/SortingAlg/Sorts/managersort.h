#ifndef MANAGERSORT_H
#define MANAGERSORT_H
#include  "SortingAlg\List\list.h"
#include  "SortingAlg\Sorts\sort.h"
#include  "SortingAlg\Sorts\bubbleSort.h"
#include <iostream>
class ManagerSort
{

public:
   ManagerSort();
    void command_sort(List* list) {
            Sort *sorttype;
            int alpha;
            //std::cout << "Choose sort\n"
             //   "[1] BubbleSort\n"
             //   "[2] InsertionSort\n"
             //   "[3] MergeSort\n"
             //   "[4] QuickSort" << std::endl;
            //scanf("%d", &alpha);
            alpha=1;


                sorttype = new BubbleSort(list);
            list->sort(sorttype);

    }
};

#endif // MANAGERSORT_H
