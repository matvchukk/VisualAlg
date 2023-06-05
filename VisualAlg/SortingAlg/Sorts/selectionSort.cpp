#include "selectionSort.h"

void SelectionSort::accept(SortVisitor* visitor) {
        visitor->visitSelectionSort(this);
    }

int SelectionSort::getLength(){
   return list->getSize();
}

int SelectionSort:: getCounter(){
    return counter;
}

void SelectionSort:: increaseCounter(){
     this->counter+=1;
}

void SelectionSort:: callQmlSlot(){
    emit callQml();
}

Step* SelectionSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

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

