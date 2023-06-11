#ifndef COMPLEXITYVISITOR_H
#define COMPLEXITYVISITOR_H
#include "SortingAlg/Sorts/bubbleSort.h"
#include "SortingAlg/Sorts/selectionSort.h"
#include "SortingAlg/Sorts/quickSort.h"
#include "sortvisitor.h"
#include <QObject>

class ComplexityVisitor : public SortVisitor {
private:
    int complexity;

public:
     ComplexityVisitor() : complexity(0) {}

     void visitBubbleSort(BubbleSort* bubbleSort) override ;
     void visitSelectionSort(SelectionSort* selectionSort) override ;
     void visitQuickSort(QuickSort* quickSort) override;

public slots:
     int getComplexity() override ;
};

#endif // COMPLEXITYVISITOR_H
