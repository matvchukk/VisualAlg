#ifndef LISTOFSTEPS_H
#define LISTOFSTEPS_H

#include <QObject>
#include "step.h"
#include "SortingAlg\Sorts\sort.h"

class ListOfSteps : public QObject
{
    Q_OBJECT
public:
    explicit ListOfSteps(QObject *parent = nullptr);
    ListOfSteps(Sort* sort): sort (sort){};
private:
    QList<Step *> steps_;
    Sort* sort;

public slots:
    int getIndexLeft(int index);
    int getIndexRight(int index);
    QList<int> getList(int index);
    Step* getSteps(int index) ;
    void backup() ;
    void clearSteps();
    int getSize();
};

#endif // LISTOFSTEPS_H
