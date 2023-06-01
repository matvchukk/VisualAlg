#include "listofsteps.h"

Step* ListOfSteps::getSteps(int index)
{
    if (index >= 0 && index < steps_.size()) {
        return steps_.at(index);
    } else {
        return nullptr;
    }
}

int ListOfSteps::getIndexLeft(int index){
    Step* Memento=this->getSteps( index);
    return Memento->copyIndexLeft;
}

int ListOfSteps::getIndexRight(int index){
    Step* Memento=this->getSteps( index);
    return Memento->copyIndexRight;
}

QList<int> ListOfSteps::getList(int index){
    Step* Memento=this->getSteps( index);
    return Memento->copylist;
}

void ListOfSteps:: backup() {
    this->steps_.push_back(this->sort->Save());
    }




