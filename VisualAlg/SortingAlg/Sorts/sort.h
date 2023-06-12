#ifndef SORT_H
#define SORT_H

#include <QObject>
#include <iostream>
#include "step.h"

class SortVisitor;

///Class implements sorting.
class Sort: public QObject
{
  Q_OBJECT

public:

   Sort() {}

   ///The function that calls the visitor to calculate a certain characteristic
   /// @param visitor The class for calculating the value of certain properties
  virtual void accept(SortVisitor* visitor) = 0;

public slots:
   /// Virtual method for sort array
   virtual void sort()=0;

   ///The function saves the current state of the array and visualization elements
   /// @returns The current state of the array and visualization elements
   virtual Step  *Save()=0;

   ///The function that triggers a signal callQml()
   virtual void  callQmlSlot()=0;

signals:
   /// The signal that triggers at each step of the algorithm in order to remember the current state
   void callQml();

   /// The signal that is triggered when the execution time is changed
   /// @param elapsedTime Execution time of a certain algorithm
   void elapsedTimeChanged(int elapsedTime);

};

#endif // SORT_H
