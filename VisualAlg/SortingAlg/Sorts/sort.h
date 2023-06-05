#ifndef SORT_H
#define SORT_H

#include <QObject>
#include <iostream>
#include "step.h"
//#include "sortvisitor.h"
class SortVisitor;
class Sort: public QObject
{
  Q_OBJECT

public:

   Sort() {}
  virtual void accept(SortVisitor* visitor) = 0;

public slots:

   virtual void sort()=0;
   virtual Step  *Save()=0;
   virtual void  callQmlSlot()=0;

signals:
   void callQml();
   void elapsedTimeChanged(int elapsedTime);

};

#endif // SORT_H
