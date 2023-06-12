#include "bubbleSort.h"
#include <QTimer>
#include <QThread>
 ///The function returns the length of the array in the List class
  /// @returns The length of the array in the List class
int BubbleSort:: getLength(){
    return list->getSize();
}

 ///The function that returns the value of variable counter
int BubbleSort:: getCounter(){
    return counter;
}

 ///The function that increments the value of a variable counter
void BubbleSort:: increaseCounter(){
     this->counter+=1;
}

///The function that calls the visitor to calculate a certain characteristic
/// @param visitor The class for calculating the value of certain properties
void BubbleSort::accept(SortVisitor* visitor)  {
        visitor->visitBubbleSort(this);
    }

 /// The signal that triggers at each step of the algorithm in order to remember the current state
void BubbleSort:: callQmlSlot(){
    emit callQml();
}

///The function saves the current state of the array and visualization elements
/// @returns The current state of the array and visualization elements
Step* BubbleSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }


 /// A method for sorting arrays by Bubble sort
void BubbleSort:: sort(){

    int length = list->getSize();

    for (int i = 0; i < (length - 1); i++) {
        for (int j = 0; j < (length- i- 1); j++) {

            double currentValue = list->getValueAtIndex(j);
            double nextValue = list->getValueAtIndex(j + 1);

            if (!(list->isListSorted( ))){
                this->indexLeft=j;
                this->indexRight=j+1;
                callQmlSlot();
             }

            if (nextValue < currentValue) {

                 list->swapItems(j, j + 1);
                 callQmlSlot();
                  this->increaseCounter();
        }
    }

}
}



