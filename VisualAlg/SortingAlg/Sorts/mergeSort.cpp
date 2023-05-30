#include "mergeSort.h"

void MergeSort::sort(){
    mergesort(0, list->getSize()-1);
    for(int i=0; i< list->getSize();i++){
      std::cout<<  list->getValueAtIndex(i)<<std::endl;
    }
}

void MergeSort::mergesort(int low, int high){

    if(low < high){
        int mid = (low+high) / 2;


        mergesort(low, mid);
        mergesort(mid+1, high);
        merge(low, high, mid);
    }
}

void MergeSort::merge(int low, int high, int mid) {
    QList<int> temp;

    int left_index = low;
    int right_index = mid + 1;

    while (left_index <= mid && right_index <= high) {
              // Highlight
        if (list->getValueAtIndex(left_index) <= list->getValueAtIndex(right_index)) {
            temp.append(list->getValueAtIndex(left_index));
            left_index++;
        } else {
            temp.append(list->getValueAtIndex(right_index));
            right_index++;
        }
    }

    while (left_index <= mid) {
              // Highlight
        temp.append(list->getValueAtIndex(left_index));
        left_index++;
    }

    while (right_index <= high) {
              // Highlight
        temp.append(list->getValueAtIndex(right_index));
        right_index++;
    }

    for (int i = low; i <= high; i++) {
        list->setValueAtIndex(i, temp.at(i - low));

    }

}



