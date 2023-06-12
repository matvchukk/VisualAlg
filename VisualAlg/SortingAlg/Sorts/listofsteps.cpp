#include "listofsteps.h"

///The function returns the value of the class Step in class ListOfSteps with index  index
/// @param index The index of class Step in class ListOfSteps
/// @returns An instance of class Step with index index that contains the state of the array and  elements of visualization
Step* ListOfSteps::getSteps(int index)
{
    if (index >= 0 && index < steps_.size()) {
        return steps_.at(index);
    } else {
        return nullptr;
    }
}

///The function returns the value of the element that is the left element that is highlighted in the element of class Step in class ListOfSteps with index  index
/// @param index The index of  class Step in class ListOfSteps
/// @returns  The value of the left element
int ListOfSteps::getIndexLeft(int index){
    Step* Memento=this->getSteps( index);
    return Memento->copyIndexLeft;
}

///The function returns the value of the element that is the right element that is highlighted in the element of class Step in class ListOfSteps with index  index
/// @param index The index of class Step in class ListOfSteps
/// @returns  The value of the right element
int ListOfSteps::getIndexRight(int index){
    Step* Memento=this->getSteps( index);
    return Memento->copyIndexRight;
}

///The function that returns a copy of the array at a certain moment
/// @param index The index of class Step in class ListOfSteps
/// @returns The array at a certain moment
QList<int> ListOfSteps::getList(int index){
    Step* Memento=this->getSteps( index);
    return Memento->copylist;
}

///The function adds an element with class Step to the array steps_, which has  copies of the state of the sorting class
void ListOfSteps:: backup() {
    this->steps_.push_back(this->sort->Save());
    }

/// The function clears the array steps_
void ListOfSteps::clearSteps()
{
    qDeleteAll(steps_);
    steps_.clear();
}

/// The function returns the size of steps_
/// @returns The size of steps_
int ListOfSteps::getSize()
{
    return steps_.size();
}




