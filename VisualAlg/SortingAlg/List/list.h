#ifndef LIST_H
#define LIST_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QList>

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
    void setItems(const QList<int>& newItems);
    void setValueAtIndex(int index,int value );

signals:
    void itemsChanged(const QList<int>& items);

};

#endif // LIST_H
