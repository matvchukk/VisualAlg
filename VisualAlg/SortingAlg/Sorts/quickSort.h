#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortingAlg/Sorts/sortvisitor.h"
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
    int counter=0;
public:

    QuickSort( List *list):
        list(list)
        {
         };
    void  quicksortlist(int left, int right);
    int partition(int left, int right);

    int getLength();
int getCounter();
void  increaseCounter();
public slots:
    Step*  Save( );
    void sort();
    void  callQmlSlot();
    void accept(SortVisitor* visitor) override ;

};

#endif // QUICKSORT_H


