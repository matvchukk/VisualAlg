#ifndef MEMORYVISITOR_H
#define MEMORYVISITOR_H
#include "SortingAlg/Sorts/bubbleSort.h"
#include "SortingAlg/Sorts/selectionSort.h"
#include "SortingAlg/Sorts/quickSort.h"
#include "sortvisitor.h"
#include <QObject>

class MemoryVisitor : public SortVisitor {
private:
    int memory;

public:
    MemoryVisitor() : memory(0) {}

    void visitBubbleSort(BubbleSort* bubbleSort) override {
        // Розрахунок обсягу пам'яті для сортування бульбашкою
       // memory = /* розрахунок обсягу пам'яті */;
    }

    void visitSelectionSort(SelectionSort* selectionSort) override {
        // Розрахунок обсягу пам'яті для сортування вибором
        //memory = /* розрахунок обсягу пам'яті */;
    }
    void visitQuickSort(QuickSort* quickSort) override {
        // Розрахунок обсягу пам'яті для сортування вибором
       // memory = /* розрахунок обсягу пам'яті */;
    }
public slots:
    int getMemory() const {
        return memory;
    }
};
#endif // MEMORYVISITOR_H
