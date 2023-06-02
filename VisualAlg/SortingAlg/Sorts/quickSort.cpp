#include "quickSort.h"

int QuickSort:: getComplexity(){
    return  complexity;
}

void QuickSort::callQmlSlot(){
    emit callQml();
}

Step*QuickSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

void QuickSort::sort(){
    int right = list->getSize() - 1;
    quicksortlist(0, right);
}

int QuickSort::partition(int left, int right){

    double pivot = list->getValueAtIndex(right);
    int i = left - 1;

    for(int j = left; j < right; j++){
        double currentValue = list->getValueAtIndex(j);

        // Highlight
        this->indexLeft=j;
        this->indexRight=right;

        if( currentValue <= pivot){
            i++;
callQmlSlot();
            list->swapItems(i, j);


        }
callQmlSlot();

    }
     list->swapItems(i+1, right);


    return i+1;
}

void QuickSort:: quicksortlist(int left, int right){
    if(left < right){
        int pivot = partition(left, right);

        quicksortlist(left, pivot-1);
        quicksortlist(pivot+1, right);
    }
}
