#ifndef SORTVISITOR_H
#define SORTVISITOR_H

#include <QObject>

class BubbleSort;
class SelectionSort;
class QuickSort;
/// The class that implements the calculation of certain properties of algorithms
class SortVisitor : public QObject
{
    Q_OBJECT

public:
    /// Virtual method of visiting an element of type BubbleSort
    /// @param bubbleSort Type of sorts
    virtual void visitBubbleSort(BubbleSort* bubbleSort) = 0;

     /// Virtual method of visiting an element of type SelectionSort
     /// @param selectionSort Type of sorts
    virtual void visitSelectionSort(SelectionSort* selectionSort) = 0;

     /// Virtual method of visiting an element of type QuickSort
     /// @param selectionSort Type of sorts
    virtual void visitQuickSort(QuickSort* selectionSort) = 0;

public slots:
    ///A virtual method that returns a specific property
    /// @returns The value of the specific property
    virtual  int getComplexity() =0;


};

#endif // SORTVISITOR_H
