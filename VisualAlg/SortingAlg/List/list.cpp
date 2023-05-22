#include  "SortingAlg\List\list.h"
#include <QDebug>




void MyList::addItem(int value)
{
    m_items.append(value);
    emit itemsChanged(m_items);
}

void MyList::swapItems(int index1, int index2)
{
    if (index1 >= 0 && index1 < m_items.size() && index2 >= 0 && index2 < m_items.size()) {
        // Міняємо місцями два елементи списку
        int temp = m_items[index1];
        m_items[index1] = m_items[index2];
        m_items[index2] = temp;

        // Відправляємо сигнал про зміну списку
        emit itemsChanged(m_items);
    }
}
