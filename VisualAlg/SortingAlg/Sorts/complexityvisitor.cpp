#include "complexityvisitor.h"
#include <cmath>

/// Virtual method of visiting an element of type BubbleSort
/// @param bubbleSort Type of sorts
void ComplexityVisitor::visitBubbleSort(BubbleSort* bubbleSort)  {
    for(int i=0;i<bubbleSort->getLength()-1;i++){
    complexity += bubbleSort->getLength()-i-1 ;}
    complexity +=bubbleSort->getCounter();

    }

/// Virtual method of visiting an element of type SelectionSort
/// @param selectionSort Type of sorts
void ComplexityVisitor::visitSelectionSort(SelectionSort* selectionSort)  {
    for(int i=0;i<selectionSort->getLength()-1;i++){
    complexity += selectionSort->getLength()-i-1 ;}
    complexity +=selectionSort->getCounter();

    }

/// Virtual method of visiting an element of type QuickSort
/// @param quickSort Type of sorts
void ComplexityVisitor::visitQuickSort(QuickSort* quickSort) {
    complexity = quickSort->getCounter();
    }

///Virtual method that returns a complexity
/// @returns The value of the complexity
int ComplexityVisitor::getComplexity()  {
    return complexity;
}
