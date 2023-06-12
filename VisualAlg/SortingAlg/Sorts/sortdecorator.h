#ifndef SORTDECORATOR_H
#define SORTDECORATOR_H
#include "sort.h"
#include <QObject>


/// The class implements the creation of auxiliary functionality
class SortDecorator : public Sort
{
protected:
    Sort* sortType;  ///< Value for saving the sort type.

public:
     ///Constructor
    SortDecorator(Sort* sortType) : sortType(sortType) {}

    /// The function calls the sort function in the sort type that is assigned to the variable sortType in the constructor
    virtual void sort() override ;

    ///The function saves the current state of the array and visualization elements
    /// @returns The current state of the array and visualization elements
    virtual Step* Save() override ;

    ///The function that triggers a signal callQml()
    virtual void  callQmlSlot() override;
};

#endif // SORTDECORATOR_H
