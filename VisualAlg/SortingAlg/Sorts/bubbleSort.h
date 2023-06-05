#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlg/Sorts/sortvisitor.h"
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
     int counter=0;

public:
       BubbleSort( List *list):
           list(list)
           {
           };

int getCounter();
void  increaseCounter();
public slots:
    void accept(SortVisitor* visitor) override ;
    int getLength();
    Step*  Save( );
    void sort();


void  callQmlSlot();
};

#endif
