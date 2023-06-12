#ifndef STEP_H
#define STEP_H

#include <QObject>

///A class that creates an exact copy of the sorting class at a certain moment of the algorithm's operation
class Step: public QObject
{
     Q_OBJECT

public:
    QList<int> copylist; ///< An array that stores a copy of the state of the array at a particular step
    int copyIndexLeft; ///< The index of the first element that should be highlighted at a certain stage
    int copyIndexRight; ///< The index of the second element that should be highlighted at a certain stage

    ///Constructor
    /// @param  copylist  An array that stores a copy of the state of the array at a particular step
    /// @param  copyIndexLeft The index of the first element that should be highlighted at a certain stage
    /// @param copyIndexRight The index of the second element that should be highlighted at a certain stage
    Step(QList<int> copylist, int copyIndexLeft, int copyIndexRight );

    ///The constructor that creates an empty instance of the class
    Step(){};

};

#endif // STEP_H
