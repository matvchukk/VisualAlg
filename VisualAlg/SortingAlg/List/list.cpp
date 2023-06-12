#include  "SortingAlg\List\list.h"
#include <QDebug>

 /// Removes all elements of the list.
void List::clearItems()
{
    m_items.clear(); 
}

/// Adds element to list.
///
///Adds an element and puts it in a certain position.
///
/// If an item is not added to the end of the list, the item that belonged to that index(and all after it) moves forward.
/// @note If the index is not specified or less than zero - adds an item to the end of the list.
/// @param   obj     The element which we want to add to list.
/// @param   index   The index on which we want to place the element.
/// @warning If index is bigger or equals to the size, than method must throw std::out_of_range.
void List::addItem(int value)
{
    m_items.append(value);
}

///Swaps elements with indices index1 and index2
/// @param index1 The index of the first element to be moved
/// @param index2 The index of the second element to be moved
void List::swapItems(int index1, int index2)
{
    if (index1 >= 0 && index1 < m_items.size() && index2 >= 0 && index2 < m_items.size()) {

        int temp = m_items[index1];
        m_items[index1] = m_items[index2];
        m_items[index2] = temp;
    }
}

/// Returns the size of list.
/// @return  size of list.
int List::getSize() const
{
    return m_items.size();
}


/// Gets element by index from list.
/// @note If index is less than 0, removed last element from the list.
/// @warning If index is bigger or equals to the size, than method must throw std::out_of_range exeption.
/// @param   index   The index of the element in the list we want to get.
/// @return  The element from list by index.
int List::getValueAtIndex(int index) const
{
    if (index >= 0 && index < m_items.size()) {
        return m_items[index];
    }
    return -1;
}

///Checks if the array is sorted
/// @returns true if the array is sorted and false otherwise
bool List::isListSorted() {
    for (int i = 1; i < this->getSize(); i++) {
        if (this->getValueAtIndex(i) <this->getValueAtIndex(i-1)) {
            return false;
        }
    }
    return true;
}


