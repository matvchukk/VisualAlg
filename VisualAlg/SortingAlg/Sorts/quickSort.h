#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
#include <QObject>

class QuickSort : public Sort
{
    Q_OBJECT
private:
    List *list;
    int indexRight;
    int indexLeft;
    int  complexity;

public:
    QuickSort( List *list):
        list(list)
        {
         };
    void  quicksortlist(int left, int right);
    int partition(int left, int right);

public slots:
    int getComplexity();
    Step*  Save( );
    void sort();
void  callQmlSlot();

};

#endif // QUICKSORT_H


