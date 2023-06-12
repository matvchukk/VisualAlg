#include "sortdecorator.h"

/// The function calls the sort function in the sort type that is assigned to the variable sortType in the constructor
 void SortDecorator :: sort()  {
    sortType->sort();
}

 /// The function calls the Save function in the sort type that is assigned to the variable sortType in the constructor
Step* SortDecorator ::Save(){
    return sortType->Save();
}

/// The function calls the callQmlSlot function in the sort type that is assigned to the variable sortType in the constructor
void SortDecorator :: callQmlSlot() {
    sortType->callQmlSlot();
}
