/*#ifndef SORT_H
#define SORT_H

#include <QObject>
#include <iostream>


class Sort: public QObject
{
  Q_OBJECT


public:

    virtual void sort() = 0;

 public slots:

    void slotSort(QList<int> steplist){
       emit  callQml( steplist);
    }

signals:
    void callQml(QList<int> steplist);
};
#endif // SORT_H
*/
