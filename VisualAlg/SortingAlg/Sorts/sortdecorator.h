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

    virtual void sort() override ;
    virtual Step* Save() override ;
    virtual void  callQmlSlot() override;
};

#endif // SORTDECORATOR_H
