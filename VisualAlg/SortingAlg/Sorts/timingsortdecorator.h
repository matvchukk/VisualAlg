#ifndef TIMINGSORTDECORATOR_H
#define TIMINGSORTDECORATOR_H

#include <QObject>
#include "sortdecorator.h"

class TimingSortDecorator : public SortDecorator
{
private:
public:

    TimingSortDecorator(Sort* sort) : SortDecorator(sort) {}

    void sort() override {

        auto startTime = std::chrono::steady_clock::now();

        SortDecorator::sort();

        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

        std::cout << "Elapsed time: " << elapsedTime << "ms";

    }

};

#endif // TIMINGSORTDECORATOR_H
