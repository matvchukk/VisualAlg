#ifndef LISTOFSTEPS_H
#define LISTOFSTEPS_H

#include <QObject>
#include "step.h"
#include "SortingAlg\Sorts\bubblesort.h"

class ListOfSteps : public QObject
{
    Q_OBJECT
public:
    explicit ListOfSteps(QObject *parent = nullptr);
    ListOfSteps(BubbleSort* bubblesort): bubblesort (bubblesort){};
private:
    QList<Step *> steps_;
    BubbleSort* bubblesort;

public slots:

    QList<Step*> getSteps() ;
    void backup() ;
    void undo() ;
};

#endif // LISTOFSTEPS_H
