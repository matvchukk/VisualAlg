#include "complexityvisitor.h"
#include <cmath>
void ComplexityVisitor::visitBubbleSort(BubbleSort* bubbleSort)  {
    for(int i=0;i<bubbleSort->getLength()-1;i++){
    complexity += bubbleSort->getLength()-i-1 ;}
    complexity +=bubbleSort->getCounter();

    }

void ComplexityVisitor::visitSelectionSort(SelectionSort* selectionSort)  {
    for(int i=0;i<selectionSort->getLength()-1;i++){
    complexity += selectionSort->getLength()-i-1 ;}
    complexity +=selectionSort->getCounter();

    }


void ComplexityVisitor::visitQuickSort(QuickSort* quickSort) {
    complexity = quickSort->getCounter();
    }

int ComplexityVisitor::getComplexity()  {
    return complexity;
}
