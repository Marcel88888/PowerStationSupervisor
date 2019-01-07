#ifndef PROJECT3_REACTOR_H
#define PROJECT3_REACTOR_H

class Reactor {

private:
    int number;
    int temperature;
    double power; // MW

public:
    void measureTemp(); // writes out the current temperature of the reactor
    int getTemp(); // returns the temperature of the reactor
    int getNumber(); // returns the number of the reactor
    double getPower(); // returns the power of the reactor
    Reactor(int, double); // constructor
};

#endif //PROJECT3_REACTOR_H
