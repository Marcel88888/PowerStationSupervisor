#ifndef PROJECT3_HEAVYWATREACTOR_H
#define PROJECT3_HEAVYWATREACTOR_H
#include "reactor.h"

class HeavyWatReactor : public Reactor {

public:
    void writeCoolant() override; // writes out the information about the type of coolant
    HeavyWatReactor(int, double, int); // constructor
};

#endif //PROJECT3_HEAVYWATREACTOR_H
