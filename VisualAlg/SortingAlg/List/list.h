#ifndef LIST_H
#define LIST_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QList>
#include <iostream>

/// The class that implements array storage and work with it
class List : public QObject
{
    Q_OBJECT
private:
    QList<int> m_items; ///< The array of elements

public:
    List(QObject *parent = nullptr) : QObject(parent) {}


public slots:

    /// Return the array of elements m_items
    /// @returns m_items
    QList<int> items() const
    {
        return m_items;
    }

    /// Removes all elements of the list.
    void clearItems();

    /// Adds element to list.
    ///
    ///Adds an element and puts it in a certain position.
    ///
    /// If an item is not added to the end of the list, the item that belonged to that index(and all after it) moves forward.
    /// @note If the index is not specified or less than zero - adds an item to the end of the list.
    /// @param   obj     The element which we want to add to list.
    /// @param   index   The index on which we want to place the element.
    /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range.
    void addItem(int value);


    ///Swaps elements with indices index1 and index2
    /// @param index1 The index of the first element to be moved
    /// @param index2 The index of the second element to be moved
    void swapItems(int index1, int index2);

    /// Returns the size of list.
    /// @return  size of list.
    int getSize() const;

    /// Gets element by index from list.
    /// @note If index is less than 0, removed last element from the list.
    /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range exeption.
    /// @param   index   The index of the element in the list we want to get.
    /// @return  The element from list by index.
    int getValueAtIndex(int index) const;

   ///Checks if the array is sorted
   /// @returns true if the array is sorted and false otherwise
    bool isListSorted();




};

#endif // LIST_H
