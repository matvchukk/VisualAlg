#include "timingsortdecorator.h"

///The function that calls the visitor to calculate a certain characteristic
/// @param visitor The class for calculating the value of certain properties
void TimingSortDecorator::accept(SortVisitor* visitor) { }

///The function that triggers signal elapsedTimeChanged for communication with qml
/// @param  elapsedTime Measured time
void TimingSortDecorator::callElapsedTimeChanged(int  elapsedTime){
    emit elapsedTimeChanged( elapsedTime);
}

///The function that runs a specific sort and measures the algorithm's execution time
void TimingSortDecorator::sort()  {

    auto startTime = std::chrono::steady_clock::now();

    SortDecorator::sort();

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    callElapsedTimeChanged(  elapsedTime);
}
