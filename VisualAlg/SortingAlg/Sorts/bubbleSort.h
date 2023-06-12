#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlg/Sorts/sortvisitor.h"
#include "SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
#include <QObject>

///Class implements sorting by Bubble sort.
class BubbleSort: public  Sort
{
Q_OBJECT

private:
     List *list; ///< A class that contains an array on which a sorting operation is performed
     int indexRight; ///< The index of the first element whose color changes during visualization
     int indexLeft; ///< The index of the second element whose color changes during visualization
     int counter=0; ///< The value of the number of performed operations of a certain type

public:
     ///Constructor of the BubbleSort class
     /// @param list The class that contains an array on which a sorting operation is performed
       BubbleSort( List *list):
           list(list)
           {
           };

    ///The function that returns the value of variable counter
    int getCounter();

    ///The function that increments the value of a variable counter
    void  increaseCounter();

public slots:
    ///The function that calls the visitor to calculate a certain characteristic
    /// @param visitor The class for calculating the value of certain properties
    void accept(SortVisitor* visitor) override ;

    ///The function returns the length of the array in the List class
    /// @returns The length of the array in the List class
    int getLength();

    ///The function saves the current state of the array and visualization elements
    /// @returns The current state of the array and visualization elements
    Step*  Save( ) override;

    /// The method for sorting arrays by Bubble sort
    void sort() override;

    /// The signal that triggers at each step of the algorithm in order to remember the current state
    void  callQmlSlot() override;
};

#endif
