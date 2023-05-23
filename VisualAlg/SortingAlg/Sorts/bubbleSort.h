#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "C:\Users\User\Desktop\PI-23\Sem 2\OOP\VisualAlg\VisualAlg\SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
///Class implements sorting by Bubble sort.
class BubbleSort : public Sort {
private:
List *list;

public:
    /// A method for sorting arrays by Bubble sort
     /// @param array is array we want to sort
     /// @param size is the size ot this array
     /// @warning The function will not work if the list is empty
     ///
BubbleSort(List *list){
  this->list = list;
};

void sort(){

    for(int i = 0; i < list->getSize(); i++){

           // Repeat for every column again, since this loop
           // sorts the highest column once ( - 1 so it doesn't
           // compare the last column to an inexistent array value
           // and -i so it doesn't compare all the values it has
           // already sorted)
           for(int j = 0; j < (list->getSize() - i) - 1; j++){

               double currentValue = list->getValueAtIndex(j);
               double nextValue = list->getValueAtIndex(j+1);

               //Highlight
             // columnManager->highlight(j, j+1);

               // If next value is smaller than the current one, swap
               // this causes the biggest value in the array to 'bubble'
               // up to the top at each step.
               if(nextValue < currentValue) list->swapItems(j, j+1);

           }
       }
};
};


#endif
