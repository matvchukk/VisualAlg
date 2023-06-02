#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
#include <QObject>

class SelectionSort : public Sort
{
    Q_OBJECT
private:
     List *list;
     int indexRight;
     int indexLeft;
     int  complexity;

public:
    SelectionSort( List *list):
        list(list)
        {
        };

public slots:
    Step*  Save( );
    void sort();
    void callQmlSlot();
    int getComplexity();
};

#endif // SELECTIONSORT_H
