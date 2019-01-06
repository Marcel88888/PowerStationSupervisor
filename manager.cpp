#include <iostream>
#include "manager.h"
#include <math.h>
using namespace std;

void Manager::addReactor(int n, int p) {
    Reactor* reactor = new Reactor(n, p);
    reacts.push_back(reactor);
}

void Manager::writeReactors() {
    cout << " R E A C T O R S" << endl << endl;
    for (int i = 0; i < reacts.size(); ++i) {
        cout << i << ":" << endl << "  Number: " << reacts[i]->getNumber() << endl;
        cout << "  Temperature: " << reacts[i]->getTemp() << endl;
        cout << "  Power [kW]: " << reacts[i]->getPower() << endl;
    }
}

int Manager::getSize() {
    return reacts.size();
}

Reactor* Manager::getReactor(int n) {
    return reacts[n];
}

void Manager::calculatePower() {
    int p = 0;
    for (int i = 0; i < reacts.size(); ++i)
        p += reacts[i]->getPower();
    totalPower = p;
}

double Manager::calculateTime(int e) {
    double time, result;
    int p;
    calculatePower();
    p = getTotalPower();
    time = 1.0*e/p*1000000/3600/24;
    result = ceil(time);
    return result;
}

int Manager::getTotalPower() {
    return totalPower;
}

Manager::Manager() {
    totalPower = 0;
}

Manager::~Manager() {
    for (int i = 0; i < reacts.size(); ++i)
        delete reacts[i];
}