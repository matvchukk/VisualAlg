#include "bubbleSort.h"
#include <QTimer>
#include <QThread>

int BubbleSort:: getLength(){
    return list->getSize();
}
int BubbleSort:: getCounter(){
    return counter;
}
void BubbleSort:: increaseCounter(){
     this->counter+=1;
}


void BubbleSort::accept(SortVisitor* visitor)  {
        visitor->visitBubbleSort(this);
    }

void BubbleSort:: callQmlSlot(){
    emit callQml();
}


Step* BubbleSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }

void BubbleSort:: sort(){

    int length = list->getSize();

    for (int i = 0; i < (length - 1); i++) {
        for (int j = 0; j < (length- i- 1); j++) {

            double currentValue = list->getValueAtIndex(j);
            double nextValue = list->getValueAtIndex(j + 1);

            if (!(list->isListSorted( ))){
                this->indexLeft=j;
                this->indexRight=j+1;
                callQmlSlot();
             }

            if (nextValue < currentValue) {

                 list->swapItems(j, j + 1);
                 callQmlSlot();
                  this->increaseCounter();
        }
    }


}
}



