#ifndef PROJECT3_PRESSWATREACTOR_H
#define PROJECT3_PRESSWATREACTOR_H
#include "reactor.h"

class PressWatReactor : public Reactor {

public:
    void writeCoolant() override; // writes out the information about the type of coolant
    PressWatReactor(int, double, int); // constructor
};

#endif //PROJECT3_PRESSWATREACTOR_H
