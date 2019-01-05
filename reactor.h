#ifndef PROJECT3_REACTOR_H
#define PROJECT3_REACTOR_H

class Reactor {

private:
    int number;
    int temperature;
    enum kind; // dorobic rodzaje i plik do tego oraz klase Manager

public:
    void measureTemp();
    int getTemp();
    Reactor();
};

#endif //PROJECT3_REACTOR_H
