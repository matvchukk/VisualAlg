#ifndef STEP_H
#define STEP_H

#include <QObject>

class Step: public QObject
{
     Q_OBJECT
public:
    QList<int> copylist;
    int copyIndexLeft;
    int copyIndexRight;

 Step(QList<int> copylist, int copyIndexLeft, int copyIndexRight );
 Step( ){};

};

#endif // STEP_H
