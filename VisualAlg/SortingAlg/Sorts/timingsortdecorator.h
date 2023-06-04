#ifndef TIMINGSORTDECORATOR_H
#define TIMINGSORTDECORATOR_H

#include <QObject>
#include "sortdecorator.h"

class TimingSortDecorator : public SortDecorator
{

public:

    void callElapsedTimeChanged(int  elapsedTime){
        emit elapsedTimeChanged( elapsedTime);
    }

    TimingSortDecorator(Sort* sort) : SortDecorator(sort) {}

    void sort() override {

        auto startTime = std::chrono::steady_clock::now();

        SortDecorator::sort();

        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

        callElapsedTimeChanged(  elapsedTime);
    }

};

#endif // TIMINGSORTDECORATOR_H
