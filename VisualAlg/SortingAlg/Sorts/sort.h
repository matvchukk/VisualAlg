#ifndef SORT_H
#define SORT_H

#include <QObject>
#include <iostream>
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
   virtual void  callQmlSlot()=0;

signals:
   void callQml();
   void elapsedTimeChanged(int elapsedTime);

};
#endif // SORT_H
