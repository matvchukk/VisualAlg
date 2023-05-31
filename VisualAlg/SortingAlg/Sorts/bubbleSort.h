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
   int getComplexity(){
       return complexity;
   }
   QList<int> getArray(){
       return list->items() ;
   }
   int getIndexLeft(){
       return indexLeft;
   }
   int getIndexRight(){
       return indexRight;
   }
   void restore(Step* copystep){
         this->list->setItems(copystep->copylist);
      this->indexLeft=  copystep->copyIndexLeft;
       this->indexRight =  copystep->copyIndexRight;

   }
   Step  *Save();
signals:
   void callQml(QList<int> steplist, int a, int b);
};

#endif
