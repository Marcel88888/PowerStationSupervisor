#include <iostream>
#include "manager.h"
#include <math.h>
#include <fstream>
using namespace std;

void Manager::addReactors(string name) {
    ifstream file;
    file.open(name.c_str());
    if(file.good()) {
        int n;
        double p;
        while (file >> n  >> p) {
            if (n < 0 || p < 0){
                cout << "Incorrect data" << endl;
                return;
            }
            Reactor* reactor = new Reactor(n, p);
            reacts.push_back(reactor);
        }
        file.close();
    }
    else {
        cout << "Program failed to open the file" << endl;
        return;
    }
}

void Manager::writeReactors() {
    cout << " R E A C T O R S" << endl << endl;
    for (int i = 0; i < reacts.size(); ++i) {
        cout << i+1 << ":" << endl << "  Number: " << reacts[i]->getNumber() << endl;
        cout << "  Temperature: " << reacts[i]->getTemp() << endl;
        cout << "  Power [kW]: " << reacts[i]->getPower() << endl;
        if (reacts[i]->getStatus() == active)
            cout << "  Status: active" << endl;
        else
            cout << "  Status: rest" << endl;
    }
}

int Manager::getSize() {
    return reacts.size();
}

Reactor* Manager::getReactor(int n) {
    return reacts[n];
}


void Manager::calculatePower() {
    double p = 0;
    for (int i = 0; i < reacts.size(); ++i)
        p += reacts[i]->getPower();
    totalPower = p;
}

double Manager::calculateTime(int e) {
    double time, result;
    double p;
    calculatePower();
    p = getTotalPower();
    time = 1.0*e/p*1000000/3600/24;
    result = ceil(time);
    return result;
}

double Manager::getTotalPower() {
    return totalPower;
}

Manager::Manager() {
    totalPower = 0;
}

Manager::~Manager() {
    for (int i = 0; i < reacts.size(); ++i)
        delete reacts[i];
}