#include <iostream>
#include "manager.h"
#include "pressWatReactor.h"
#include "heavyWatReactor.h"
#include "gasCoolReactor.h"
#include <math.h>
#include <fstream>
using namespace std;

void Manager::addReactors(string name) {
    int a;
    ifstream file;
    file.open(name.c_str());
    if(file.good()) {
        int n;
        double p;
        while (file >> a >> n  >> p) {
            if (a < 1 || a > 3 || n < 0 || p < 0) {
                cout << "Incorrect data" << endl;
                return;
            }
            if (a == 1) {
                Reactor *reactor = new PressWatReactor(n, p, a);
                reacts.push_back(reactor);
            }
            else if (a == 2) {
                Reactor *reactor = new HeavyWatReactor(n, p, a);
                reacts.push_back(reactor);
            }
            else {
                Reactor *reactor = new GasCoolReactor(n, p, a);
                reacts.push_back(reactor);
            }
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
        if (reacts[i]->getType() == 1) {
            cout << "  Type: pressurized water" << endl;
        }
        else if (reacts[i]->getType() == 2) {
            cout << "  Type: heavy water" << endl;
        }
        else {
            cout << "  Type: gas-cooled" << endl;
        }
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