#include "step.h"

///Constructor
/// @param  copylist  An array that stores a copy of the state of the array at a particular step
/// @param  copyIndexLeft The index of the first element that should be highlighted at a certain stage
/// @param copyIndexRight The index of the second element that should be highlighted at a certain stage
 Step::Step(QList<int> copylist, int copyIndexLeft, int copyIndexRight ){
     this->copylist = copylist;
     this->copyIndexLeft = copyIndexLeft;
     this->copyIndexRight = copyIndexRight;
};
