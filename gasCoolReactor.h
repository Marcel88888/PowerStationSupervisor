#ifndef PROJECT3_GASCOOLREACTOR_H
#define PROJECT3_GASCOOLREACTOR_H
#include "reactor.h"

class GasCoolReactor : public Reactor {

public:
    void writeCoolant() override; // writes out the information about the type of coolant
    GasCoolReactor(int, double, int); // constructor
};

#endif //PROJECT3_GASCOOLREACTOR_H
