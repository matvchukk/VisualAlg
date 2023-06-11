#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SortingAlg/Sorts/sortvisitor.h"
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
     int counter=0;
public:
     SelectionSort( List *list):
         list(list)
         {
         };

     int getLength();
int getCounter();
void  increaseCounter();
public slots:
    Step*  Save( );
    void sort();
    void  callQmlSlot();
    void accept(SortVisitor* visitor) override ;

};

#endif // SELECTIONSORT_H
