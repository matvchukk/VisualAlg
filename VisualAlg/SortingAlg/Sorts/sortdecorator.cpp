#include "sortdecorator.h"

 void SortDecorator :: sort()  {
    sortType->sort();
}

Step* SortDecorator ::Save(){
    return sortType->Save();
}

void SortDecorator :: callQmlSlot() {
    sortType->callQmlSlot();
}
