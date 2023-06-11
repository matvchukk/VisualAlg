#include "heightdecorator.h"

template <typename T>
int HeightDecorator<T>::getHeight() const {
    return height;
}

template <typename T>
void HeightDecorator<T>::setHeight(int height) const {
    this->height = height;
}
