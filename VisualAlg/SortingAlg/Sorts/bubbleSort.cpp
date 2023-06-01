#include "bubbleSort.h"
#include <QTimer>
#include <QThread>

bool isListSorted(const QList<int>& list) {
    for (int i = 1; i < list.size(); i++) {
        if (list.at(i) < list.at(i - 1)) {
            return false;
        }
    }
    return true;
}

Step* BubbleSort:: Save( ) {
    return new Step(this->list->items(),this->indexLeft, this->indexRight);
  }


void BubbleSort:: sort(){

    int  complexity=0;
    int length = list->getSize();
    bool swapped = true;

    for (int i = 0; i < (length - 1); i++) {
        swapped = false;
        for (int j = 0; j < (length- i- 1); j++) {

            double currentValue = list->getValueAtIndex(j);
            double nextValue = list->getValueAtIndex(j + 1);

            if (!isListSorted( list->items())){
                this->indexLeft=j;
                this->indexRight=j+1;
                emit callQml(list->items(), j, j + 1);
             }

            if (nextValue < currentValue) {
                 complexity = complexity + 1;
                 list->swapItems(j, j + 1);
                 emit callQml(list->items(), j, j + 1);

                swapped = true;

        }
    }
}
 this->complexity=complexity;
}



