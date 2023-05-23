#ifndef MANAGERSORTWRAPPER_H
#define MANAGERSORTWRAPPER_H

#include <QObject>
#include "managersort.h"

class ManagerSortWrapper : public QObject
{
    Q_OBJECT

public:
    ManagerSortWrapper(QObject *parent = nullptr) : QObject(parent), m_managerSort() {}

    Q_INVOKABLE void commandSort(List* list) {
        m_managerSort.command_sort(list);
    }

private:
    ManagerSort m_managerSort;
};

#endif // MANAGERSORTWRAPPER_H
