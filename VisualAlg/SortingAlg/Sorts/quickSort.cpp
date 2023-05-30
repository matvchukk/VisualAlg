#include "quickSort.h"

void QuickSort::sort(){
    int right = list->getSize() - 1;
    quicksort(0, right);
}

int QuickSort::partition(int left, int right){
    QTimer timer;
    timer.setInterval(1000);
    double pivot = list->getValueAtIndex(right);
    int i = left - 1;

    for(int j = left; j < right; ++j){
        double currentValue = list->getValueAtIndex(j);

        // Highlight

        if( currentValue <= pivot){
            i++;
            list->swapItems(i, j);
            QTimer::singleShot(20000 * j, [this, j]() {
                           emit callQml(list->items());
                       });
            timer.start();
                        QEventLoop loop;
                        QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
                        loop.exec();
        }
    }
     list->swapItems(i+1, right);
     QTimer::singleShot(20000 , [this]() {
                    emit callQml(list->items());
                });
     timer.start();
                 QEventLoop loop;
                 QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
                 loop.exec();
    return i+1;
}

void QuickSort::quicksort(int left, int right){
    if(left < right){
        int pivot = partition(left, right);

       quicksort(left, pivot-1);
       quicksort(pivot+1, right);
    }
}
