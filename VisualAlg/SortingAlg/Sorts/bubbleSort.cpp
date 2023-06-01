#include "bubbleSort.h"
#include <QTimer>
#include <QThread>



Step* BubbleSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }


void BubbleSort:: sort(){

    int  complexity=0;
    int length = list->getSize();

    for (int i = 0; i < (length - 1); i++) {
        for (int j = 0; j < (length- i- 1); j++) {

            double currentValue = list->getValueAtIndex(j);
            double nextValue = list->getValueAtIndex(j + 1);

            if (!isListSorted( list->items())){

                this->indexLeft=j;
                this->indexRight=j+1;
                callQmlSlot();
             }

            if (nextValue < currentValue) {
                 complexity = complexity + 1;
                 list->swapItems(j, j + 1);
                 callQmlSlot();


        }
    }
}
 this->complexity=complexity;
}



