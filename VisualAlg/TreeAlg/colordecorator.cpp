#include "colordecorator.h"

template <typename T>
bool ColorDecorator<T>::getColor() const {
    return color;
}

template <typename T>
void ColorDecorator<T>::setColor(bool color) const {
    this->color = color;
}
