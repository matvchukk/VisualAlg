#include "timingsortdecorator.h"

void TimingSortDecorator::accept(SortVisitor* visitor) { }

void TimingSortDecorator::callElapsedTimeChanged(int  elapsedTime){
    emit elapsedTimeChanged( elapsedTime);
}

void TimingSortDecorator::sort()  {

    auto startTime = std::chrono::steady_clock::now();

    SortDecorator::sort();

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    callElapsedTimeChanged(  elapsedTime);
}
