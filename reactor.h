#ifndef PROJECT3_REACTOR_H
#define PROJECT3_REACTOR_H

enum status
{
    active,
    rest
};

class Reactor {

protected:
    int number;
    int temperature;
    double power; // MW
    status stat;
    int type;

public:
    virtual void writeCoolant();
    int getTemp(); // returns the temperature of the reactor
    int getNumber(); // returns the number of the reactor
    double getPower(); // returns the power of the reactor
    status getStatus(); // return the status of the power station
    int getType(); // returns the type of the reactor
    void setTemp(int); // sets the temperature of the reactor
    void setStatus(status); // sets the status of the reactor
    Reactor(int, double, int); // constructor
};

#endif //PROJECT3_REACTOR_H
