#include "selectionSort.h"

int SelectionSort::getComplexity(){
    return  complexity;
}

Step* SelectionSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

void SelectionSort:: sort(){
    int length = list->getSize();
    int  complexity=0;
    for(int i = 0; i < length ; i++){


        double currentMinimum = list->getValueAtIndex(i);
        int currentMinimumIndex = i;


        for(int j = i+1; j < length; j++){

            double currentValue = list->getValueAtIndex(j);


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
         complexity=complexity+1;
         list->swapItems(i, currentMinimumIndex);

           callQmlSlot();

    }
    this->complexity=complexity;
   }

