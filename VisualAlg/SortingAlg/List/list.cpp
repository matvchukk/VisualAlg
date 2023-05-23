#include  "SortingAlg\List\list.h"
#include <QDebug>




void List::addItem(int value)
{
    m_items.append(value);
    emit itemsChanged(m_items);
}

void List::swapItems(int index1, int index2)
{
    if (index1 >= 0 && index1 < m_items.size() && index2 >= 0 && index2 < m_items.size()) {

        int temp = m_items[index1];
        m_items[index1] = m_items[index2];
        m_items[index2] = temp;


        emit itemsChanged(m_items);
    }
}

int List::getSize() const
{
    return m_items.size();
}

int List::getValueAtIndex(int index) const
{
    if (index >= 0 && index < m_items.size()) {
        return m_items[index];
    }
    return -1;
}
