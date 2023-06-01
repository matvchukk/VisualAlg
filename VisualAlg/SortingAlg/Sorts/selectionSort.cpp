#include "selectionSort.h"


Step* SelectionSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

void SelectionSort:: sort(){
    int length = list->getSize();

    for(int i = 0; i < length ; i++){


        double currentMinimum = list->getValueAtIndex(i);
        int currentMinimumIndex = i;


        for(int j = i+1; j < length; j++){

            double currentValue = list->getValueAtIndex(j);


            if (!isListSorted( list->items())){

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
           callQmlSlot();

    }
}
