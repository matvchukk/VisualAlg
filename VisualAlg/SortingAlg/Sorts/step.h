#ifndef STEP_H
#define STEP_H

#include <QObject>

class Step
{
public:
    QList<int> copylist;
    int copyIndexLeft;
    int copyIndexRight;

 Step(QList<int> copylist, int copyIndexLeft, int copyIndexRight );

};

#endif // STEP_H
