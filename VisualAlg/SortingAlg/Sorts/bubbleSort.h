#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
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
void sort(){
QTimer timer;
 timer.setInterval(1000);
    for(int i = 0; i < list->getSize(); i++){

           for(int j = 0; j < (list->getSize() - i) - 1; j++){

               double currentValue = list->getValueAtIndex(j);
               double nextValue = list->getValueAtIndex(j+1);

               //Highlight

               if(nextValue < currentValue) list->swapItems(j, j+1);
               QTimer::singleShot(10000 * j, [this, j]() {
                              emit callQml(list->items());
                          });
               timer.start();
                           QEventLoop loop;
                           QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
                           loop.exec();
           }
       }
}
signals:
    void callQml(QList<int> steplist);
};


#endif
