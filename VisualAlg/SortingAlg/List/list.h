#ifndef LIST_H
#define LIST_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QList>
#include  "SortingAlg\Sorts\sort.h"
#include <iostream>
class List : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<int> items READ items NOTIFY itemsChanged)

private:
    QList<int> m_items;

public:
    List(QObject *parent = nullptr) : QObject(parent) {}

    QList<int> items() const
    {
        return m_items;
    }

public slots:
    void addItem(int value);
    void swapItems(int index1, int index2);
    int getSize() const;
    int getValueAtIndex(int index) const;
    void sort(Sort* sorttype)  {

         sorttype->sort();

       }
    void setItems(const QList<int>& newItems) {
        if (m_items != newItems) {
            m_items = newItems;
            emit itemsChanged(m_items);
        }
    }
signals:
    void itemsChanged(const QList<int>& items);
};

#endif // LIST_H
