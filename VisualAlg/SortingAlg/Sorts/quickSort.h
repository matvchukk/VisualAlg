#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortingAlg\List\list.h"
#include <QObject>
#include <QTimer>

class QuickSort : public QObject
{
    Q_OBJECT
private:
    List *list;

public:

    QuickSort( List *list):
        list(list)
        {
         };
    void  quicksortlist(int left, int right);
    int partition(int left, int right);

public slots:
    void sort();

signals:
    void callQml(QList<int> steplist);

};

#endif // QUICKSORT_H


