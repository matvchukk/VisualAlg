#ifndef SORT_H
#define SORT_H

#include <QObject>
#include <iostream>
#include "SortingAlg\List\list.h"
#include "step.h"

class Sort: public QObject
{
  Q_OBJECT

public:
    Sort(){

    };

 public slots:

   virtual void sort()=0;
   virtual Step  *Save()=0;
    bool isListSorted(const QList<int>& list);

signals:
   void callQml();

};
#endif // SORT_H
