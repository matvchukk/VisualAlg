#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
#include <QTimer>

class MergeSort: public QObject
{
Q_OBJECT

private:
List *list;

public:
    MergeSort( List *list):
        list(list)
        {
        };
void mergesort(int low, int high);
void merge(int low, int high, int mid);
public slots:
    void sort();
signals:
    void callQml(QList<int> steplist);
};

#endif // MERGESORT_H
