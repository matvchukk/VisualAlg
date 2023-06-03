#ifndef SORTDECORATOR_H
#define SORTDECORATOR_H
#include "sort.h"
#include <QObject>

class SortDecorator : public Sort
{
protected:
    Sort* sortType;

public:
    SortDecorator(Sort* sortType) : sortType(sortType) {}

    virtual void sort() override {
        sortType->sort();
    }

    virtual Step* Save() override {
        return sortType->Save();
    }
    virtual void  callQmlSlot() override{
        sortType->callQmlSlot();
    }
};

#endif // SORTDECORATOR_H
