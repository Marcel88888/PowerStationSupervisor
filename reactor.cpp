#include <iostream>
#include <cstdlib>
#include <ctime>
#include "reactor.h"
using namespace std;

void Reactor::measureTemp() {
    srand (static_cast <unsigned int> (time (nullptr) ) );
    int t = getTemp();
    int a, x = 0;
    cout << "Temperature in the reactor: " << endl << endl;
    for (int i = 0; i < 50; ++i) {
        t = rand() % 101;
        a = rand() % 2;
        if (a == 0) temperature -= t;
        else temperature += t;
        cout << temperature << endl;
        if (temperature >= 1200) {
            cout << "Temperature is TOO HIGH! Try to REDUCE it!!!" << endl;
            x = 1;
            break;
        }
        if (temperature <= 800) {
            cout << "Temperature is TOO LOW! Try to RAISE it!!!" << endl;
            x = 1;
            break;
        }
    }
    if (x == 0)
        cout << "Temperature is OK." << endl;
}

int Reactor::getTemp() {
    return temperature;
}

int Reactor::getNumber() {
    return number;
}

int Reactor::getPower() {
    return power;
}

Reactor::Reactor(int num, int pow) {
    number = num;
    power = pow;
    temperature = 1000;
}