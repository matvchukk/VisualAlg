#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortingAlg/Sorts/sortvisitor.h"
#include "SortingAlg\List\list.h"
#include <iostream>
#include "sort.h"
#include <QObject>

///Class implements sorting by Quick sort.
class QuickSort : public Sort
{
    Q_OBJECT
private:
    List *list; ///< A class that contains an array on which a sorting operation is performed
    int indexRight; ///< The index of the first element whose color changes during visualization
    int indexLeft; ///< The index of the second element whose color changes during visualization
    int counter=0; ///< The value of the number of performed operations of a certain type

public:
    ///Constructor of the  QuickSort class
    /// @param list The class that contains an array on which a sorting operation is performed
    QuickSort( List *list):
        list(list)
        {
         };

     ///The function returns the length of the array in the List class
     /// @returns The length of the array in the List class
     int getLength();

     ///The function that returns the value of variable counter
     int getCounter();

private:

     ///The function that increments the value of a variable counter
    void  increaseCounter();

    ///The function performs partial sorting of the array left to right index
     ///@param array Array we want to sort
     ///@param left The starting element of the subarray
     ///@param right The final element of the subarray
    void  quicksortlist(int left, int right);

    /// The Partition function returns an index with a supporting element dividing the array into two parts; the left - the elements of which are smaller than the supporting element, and the right - the elements of which are larger than the supporting element
    /// @param left The starting element of the subarray
    /// @param right The final element of the subarray
    /// @returns An index with a supporting element
    int partition(int left, int right);

public slots:

    ///The function saves the current state of the array and visualization elements
    /// @returns The current state of the array and visualization elements
    Step*  Save( ) override;

    /// The method for sorting arrays by Quick sort
    void sort() override ;

    /// The signal that triggers at each step of the algorithm in order to remember the current state
    void  callQmlSlot() override;

    ///The function that calls the visitor to calculate a certain characteristic
    /// @param visitor The class for calculating the value of certain properties
    void accept(SortVisitor* visitor) override ;

};

#endif // QUICKSORT_H


