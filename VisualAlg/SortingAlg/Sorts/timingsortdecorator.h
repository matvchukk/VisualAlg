#ifndef TIMINGSORTDECORATOR_H
#define TIMINGSORTDECORATOR_H

#include <QObject>
#include "sortdecorator.h"

class TimingSortDecorator : public SortDecorator
{

public:
    TimingSortDecorator(Sort* sort) : SortDecorator(sort) {}
    void accept(SortVisitor* visitor) override ;
    void callElapsedTimeChanged(int  elapsedTime);
    void sort() override ;

};

#endif // TIMINGSORTDECORATOR_H
