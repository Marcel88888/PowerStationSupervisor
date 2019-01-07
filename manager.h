#ifndef PROJECT3_MANAGER_H
#define PROJECT3_MANAGER_H
#include <vector>
#include <iostream>
#include "reactor.h"
using namespace std;

class Manager {

private:
    double totalPower;
    vector <Reactor*> reacts;
public:
    void addReactors(string); // adds a reactor to the vector of reactors
    void writeReactors(); // writes out information of all the reactors
    int getSize(); // returns the size of reactors' vector
    double getTotalPower(); // returns the total power of the power station
    void calculatePower(); // calculates the total power of the power station and sets totalPower argument
    double calculateTime(int); // returns the amount of time the power station will produce some amount of energy
    Reactor* getReactor(int); // return the pointer to the element of reactors' vector
    Manager(); // constructor
    ~Manager(); // destructor
};
#endif //PROJECT3_MANAGER_H
