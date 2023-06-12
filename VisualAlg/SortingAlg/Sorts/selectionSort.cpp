#include "selectionSort.h"

///The function that calls the visitor to calculate a certain characteristic
/// @param visitor The class for calculating the value of certain properties
void SelectionSort::accept(SortVisitor* visitor) {
        visitor->visitSelectionSort(this);
    }

///The function returns the length of the array in the List class
/// @returns The length of the array in the List class
int SelectionSort::getLength(){
   return list->getSize();
}

 ///The function that returns the value of variable counter
int SelectionSort:: getCounter(){
    return counter;
}

///The function that increments the value of a variable counter
void SelectionSort:: increaseCounter(){
     this->counter+=1;
}

/// The signal that triggers at each step of the algorithm in order to remember the current state
void SelectionSort:: callQmlSlot(){
    emit callQml();
}

///The function saves the current state of the array and visualization elements
/// @returns The current state of the array and visualization elements
Step* SelectionSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

/// The method for sorting arrays by  Selection sort
void SelectionSort:: sort(){
    int length = list->getSize();

    for(int i = 0; i < length ; i++){

        int currentMinimum = list->getValueAtIndex(i);
        int currentMinimumIndex = i;

        for(int j = i+1; j < length; j++){

            int currentValue = list->getValueAtIndex(j);

            if (!(list->isListSorted( ))){

                this->indexLeft=currentMinimumIndex;
                this->indexRight=j;
                callQmlSlot();
             }

            if (currentValue < currentMinimum) {

                currentMinimum = currentValue;
                currentMinimumIndex = j;
            }
        }

         list->swapItems(i, currentMinimumIndex);
         this->increaseCounter();

           callQmlSlot();
    }
   }

