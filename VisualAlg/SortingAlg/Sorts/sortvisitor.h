#ifndef SORTVISITOR_H
#define SORTVISITOR_H

#include <QObject>

class BubbleSort;
class SelectionSort;
class QuickSort;

class SortVisitor : public QObject
{
    Q_OBJECT

public:
    virtual void visitBubbleSort(BubbleSort* bubbleSort) = 0;
    virtual void visitSelectionSort(SelectionSort* selectionSort) = 0;
    virtual void visitQuickSort(QuickSort* selectionSort) = 0;

public slots:

    virtual  int getComplexity() =0;


};

#endif // SORTVISITOR_H
