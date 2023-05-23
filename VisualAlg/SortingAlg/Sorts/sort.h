#ifndef SORT_H
#define SORT_H


#include <iostream>


class Sort {
public:

    virtual void sort() = 0;

protected:

    /// This function  compares two objects of type T.
    /// @returns If the objects are equal, the function returns 0, and if the first object is greater than the second, it returns 1, otherwise -1.
    int compare(int& a, int& b) {
        if (a == b) return 0;
        else return a > b;
    };


};
#endif // SORT_H
