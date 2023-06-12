#ifndef COMPLEXITYVISITOR_H
#define COMPLEXITYVISITOR_H
#include "SortingAlg/Sorts/bubbleSort.h"
#include "SortingAlg/Sorts/selectionSort.h"
#include "SortingAlg/Sorts/quickSort.h"
#include "sortvisitor.h"
#include <QObject>

/// The class that implements the calculation of the complexity of algorithms
class ComplexityVisitor : public SortVisitor {
private:
    int complexity; ///< The value of complexity

public:
     ///Constructor
     ComplexityVisitor() : complexity(0) {}

     /// Virtual method of visiting an element of type BubbleSort
     /// @param bubbleSort Type of sorts
     void visitBubbleSort(BubbleSort* bubbleSort) override ;

     /// Virtual method of visiting an element of type SelectionSort
     /// @param selectionSort Type of sorts
     void visitSelectionSort(SelectionSort* selectionSort) override ;

     /// Virtual method of visiting an element of type QuickSort
     /// @param quickSort Type of sorts
     void visitQuickSort(QuickSort* quickSort) override;

public slots:

     ///Virtual method that returns a complexity
     /// @returns The value of the complexity
     int getComplexity() override ;
};

#endif // COMPLEXITYVISITOR_H
