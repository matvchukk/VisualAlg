#include "quickSort.h"

///The function that calls the visitor to calculate a certain characteristic
/// @param visitor The class for calculating the value of certain properties
void QuickSort::accept(SortVisitor* visitor) {
        visitor->visitQuickSort(this);
    }

///The function returns the length of the array in the List class
/// @returns The length of the array in the List class
int QuickSort::getLength(){
   return list->getSize();
}

 ///The function that returns the value of variable counter
int QuickSort:: getCounter(){
    return counter;
}

 ///The function that increments the value of a variable counter
void QuickSort:: increaseCounter(){
     this->counter+=1;
}

///The function saves the current state of the array and visualization elements
/// @returns The current state of the array and visualization elements
Step*QuickSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

/// The method for sorting arrays by Quick sort
void QuickSort::sort(){
    int right = list->getSize() - 1;
    quicksortlist(0, right);

}

/// The signal that triggers at each step of the algorithm in order to remember the current state
void QuickSort:: callQmlSlot(){
    emit callQml();
}


/// The Partition function returns an index with a supporting element dividing the array into two parts; the left - the elements of which are smaller than the supporting element, and the right - the elements of which are larger than the supporting element
/// @param left The starting element of the subarray
/// @param right The final element of the subarray
/// @returns An index with a supporting element
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

///The function performs partial sorting of the array left to right index
 ///@param array Array we want to sort
 ///@param left The starting element of the subarray
 ///@param right The final element of the subarray
void QuickSort:: quicksortlist(int left, int right){
    if(left < right){
        int pivot = partition(left, right);

        quicksortlist(left, pivot-1);
        quicksortlist(pivot+1, right);
    }
}
