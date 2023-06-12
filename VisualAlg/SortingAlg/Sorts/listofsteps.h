#ifndef LISTOFSTEPS_H
#define LISTOFSTEPS_H

#include <QObject>
#include "step.h"
#include "SortingAlg\Sorts\sort.h"

///A class that stores instances of the Steps class, whose elements are exact copies of the sorting class at a certain moment of the algorithm's operation.
class ListOfSteps : public QObject
{
    Q_OBJECT
public:
    explicit ListOfSteps(QObject *parent = nullptr);

    ///Constructor
    ListOfSteps(Sort* sort): sort (sort){};
private:
    QList<Step *> steps_; ///< An array whose elements are instances of the Steps class, which are exact copies of the sorting class at a certain moment of the algorithm's operation.
    Sort* sort; ///< A sort type whose intermediate steps are stored in an array steps_

public slots:


    ///The function returns the value of the element that is the left element that is highlighted in the element of class Step in class ListOfSteps with index  index
    /// @param index The index of  class Step in class ListOfSteps
    /// @returns  The value of the left element
    int getIndexLeft(int index);

    ///The function returns the value of the element that is the right element that is highlighted in the element of class Step in class ListOfSteps with index  index
    /// @param index The index of class Step in class ListOfSteps
    /// @returns  The value of the right element
    int getIndexRight(int index);

    ///The function that returns a copy of the array at a certain moment
    /// @param index The index of class Step in class ListOfSteps
    /// @returns The array at a certain moment
    QList<int> getList(int index);

    ///The function returns the value of the class Step in class ListOfSteps with index  index
    /// @param index The index of class Step in class ListOfSteps
    /// @returns An instance of class Step with index index that contains the state of the array and  elements of visualization
    Step* getSteps(int index) ;

    ///The function adds an element with class Step to the array steps_, which has  copies of the state of the sorting class
    void backup() ;

    /// The function clears the array steps_
    void clearSteps();

    /// The function returns the size of steps_
    /// @returns The size of steps_
    int getSize();
};

#endif // LISTOFSTEPS_H
