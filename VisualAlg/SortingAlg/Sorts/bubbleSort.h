#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlg\List\list.h"
#include <iostream>
#include "step.h"
#include <QObject>

///Class implements sorting by Bubble sort.
class BubbleSort: public  QObject
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
    void sort();
    Step  *Save();
signals:
   void callQml(QList<int> steplist, int a, int b);
};

#endif
