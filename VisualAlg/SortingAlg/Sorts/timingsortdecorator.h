#ifndef TIMINGSORTDECORATOR_H
#define TIMINGSORTDECORATOR_H

#include <QObject>
#include "sortdecorator.h"

/// The class implements the creation of auxiliary functionality, in particular, measuring the running time of the algorithm
class TimingSortDecorator : public SortDecorator
{

public:
     ///Constructor
    TimingSortDecorator(Sort* sort) : SortDecorator(sort) {}

    ///The function that calls the visitor to calculate a certain characteristic
    /// @param visitor The class for calculating the value of certain properties
    void accept(SortVisitor* visitor) override ;

    ///The function that triggers signal elapsedTimeChanged for communication with qml
    /// @param  elapsedTime Measured time
    void callElapsedTimeChanged(int  elapsedTime);

    ///The function that runs a specific sort and measures the algorithm's execution time
    void sort() override ;

};

#endif // TIMINGSORTDECORATOR_H
