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
   public:
    int elapsedTime() const {
           return m_elapsedTime;
       }

   signals:
       // Emit a signal to notify when the elapsed time changes
       void elapsedTimeChanged(int elapsedTime);

   protected:
       // Helper method to update the elapsed time
       void setElapsedTime(int elapsedTime) {
           if (m_elapsedTime != elapsedTime) {
               m_elapsedTime = elapsedTime;
               emit elapsedTimeChanged(m_elapsedTime);
           }
       }

   private:
       int m_elapsedTime = 0;
signals:
   void callQml();

};
#endif // SORT_H
