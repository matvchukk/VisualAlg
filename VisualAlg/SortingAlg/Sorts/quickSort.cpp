#include "quickSort.h"

void QuickSort::accept(SortVisitor* visitor) {
        visitor->visitQuickSort(this);
    }

int QuickSort::getLength(){
   return list->getSize();
}

int QuickSort:: getCounter(){
    return counter;
}

void QuickSort:: increaseCounter(){
     this->counter+=1;
}

Step*QuickSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

void QuickSort::sort(){
    int right = list->getSize() - 1;
    quicksortlist(0, right);

}

void QuickSort:: callQmlSlot(){
    emit callQml();
}

int QuickSort::partition(int left, int right){

    double pivot = list->getValueAtIndex(right);
    int i = left - 1;

    for(int j = left; j < right; j++){
        double currentValue = list->getValueAtIndex(j);

        this->indexLeft=j;
        this->indexRight=right;
        this->increaseCounter();
        if( currentValue <= pivot){
            i++;
            callQmlSlot();
            this->increaseCounter();
            list->swapItems(i, j);


        }
            callQmlSlot();

    }
         this->increaseCounter();
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
