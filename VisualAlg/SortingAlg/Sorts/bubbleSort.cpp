#include "bubbleSort.h"

void BubbleSort:: sort(){
int  complexity=0;
    for(int i = 0; i < list->getSize(); i++){

           for(int j = 0; j < (list->getSize() - i) - 1; j++){

               double currentValue = list->getValueAtIndex(j);
               double nextValue = list->getValueAtIndex(j+1);

               if(nextValue < currentValue)
               {list->swapItems(j, j+1);
                   emit callQml(list->items());
                   complexity=complexity+1;}
           }
       }
    this->complexity=complexity;
    //return complexity;
}


