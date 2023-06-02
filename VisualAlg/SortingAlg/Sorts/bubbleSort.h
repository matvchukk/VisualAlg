#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
#include <QObject>

///Class implements sorting by Bubble sort.
class BubbleSort: public  Sort
{
Q_OBJECT

private:
     List *list;
     int indexRight;
     int indexLeft;
     int  complexity;

public:
    BubbleSort( List *list):
        list(list)
        {
        };

public slots:
    int getComplexity();
    Step*  Save( );
    void sort();
    void callQmlSlot();

};

#endif
