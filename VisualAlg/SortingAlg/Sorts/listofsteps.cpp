#include "listofsteps.h"


QList<Step*>  ListOfSteps:: getSteps()
    {
    return steps_;
    }

void ListOfSteps:: backup() {

    this->steps_.push_back(this->bubblesort->Save());
    }

void ListOfSteps::undo() {
    if (!this->steps_.size()) {
     return;
    }
    Step* memento = this->steps_.back();
    this->steps_.pop_back();

    try {
    this->bubblesort ->restore(memento);
    } catch (...) {
    this->undo();
    }
}

