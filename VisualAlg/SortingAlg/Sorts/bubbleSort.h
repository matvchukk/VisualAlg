#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlg\List\list.h"
#include <iostream>
//#include "sort.h"
#include <QTimer>

///Class implements sorting by Bubble sort.
class BubbleSort: public QObject
{
Q_OBJECT

private:
List *list;

public:
    BubbleSort( List *list):
        list(list)
        {
        };

public slots:
   int sort();

signals:
    void callQml(QList<int> steplist);
};

#endif
