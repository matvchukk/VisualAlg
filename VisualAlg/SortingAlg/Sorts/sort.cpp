#include "sort.h"

bool Sort::isListSorted(const QList<int>& list) {
    for (int i = 1; i < list.size(); i++) {
        if (list.at(i) < list.at(i - 1)) {
            return false;
        }
    }
    return true;
}
